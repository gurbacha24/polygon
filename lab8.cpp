#include <iostream>
#include <vector>
#include <functional> // Для std::less и std::greater

template <typename T, typename Comparator = std::less<T>>
class Heap {
private:
    std::vector<T> heap; // Вектор для хранения элементов кучи
    Comparator comp; // Компаратор для сравнения элементов

    // Просеивание вверх (восстановление свойства кучи после вставки)
    // Сложность: O(log n)
    void siftUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2; // Индекс родителя
            if (comp(heap[index], heap[parentIndex])) { // Используем компаратор
                std::swap(heap[index], heap[parentIndex]); // Меняем местами
                index = parentIndex; // Переходим к родителю
            } else {
                break; // Свойство кучи восстановлено
            }
        }
    }

    // Просеивание вниз (восстановление свойства кучи после извлечения или удаления)
    // Сложность: O(log n)
    void siftDown(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1; // Индекс левого потомка
            int rightChild = 2 * index + 2; // Индекс правого потомка
            int target = index; // Индекс элемента, который нужно переместить

            // Сравниваем с левым потомком
            if (leftChild < size && comp(heap[leftChild], heap[target])) {
                target = leftChild;
            }

            // Сравниваем с правым потомком
            if (rightChild < size && comp(heap[rightChild], heap[target])) {
                target = rightChild;
            }

            // Если целевой элемент не текущий, меняем их местами
            if (target != index) {
                std::swap(heap[index], heap[target]);
                index = target; // Переходим к потомку
            } else {
                break; // Свойство кучи восстановлено
            }
        }
    }

public:
    // Вставка элемента
    // Сложность: O(log n)
    void insert(const T& value) {
        heap.push_back(value); // Добавляем элемент в конец
        siftUp(heap.size() - 1); // Просеиваем вверх
    }

    // Извлечение корневого элемента
    // Сложность: O(log n)
    T extractTop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty"); // Если куча пуста
        }
        T top = heap[0]; // Запоминаем корневой элемент
        heap[0] = heap.back(); // Перемещаем последний элемент в корень
        heap.pop_back(); // Удаляем последний элемент
        siftDown(0); // Просеиваем вниз
        return top; // Возвращаем корневой элемент
    }

    // Получение корневого элемента без удаления
    // Сложность: O(1)
    T peek() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty"); // Если куча пуста
        }
        return heap[0]; // Возвращаем корневой элемент
    }

    // Построение кучи из массива
    // Сложность: O(n)
    void buildHeap(const std::vector<T>& array) {
        heap = array; // Копируем массив
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            siftDown(i); // Просеиваем вниз для каждого элемента
        }
    }

    // Удаление элемента по индексу
    // Сложность: O(log n)
    void deleteElement(int index) {
        if (index < 0 || index >= heap.size()) {
            throw std::out_of_range("Index out of range"); // Проверка корректности индекса
        }
        heap[index] = heap.back(); // Перемещаем последний элемент на место удаляемого
        heap.pop_back(); // Удаляем последний элемент
        siftDown(index); // Просеиваем вниз
    }

    // Изменение приоритета элемента
    // Сложность: O(log n)
    void changePriority(int index, const T& newValue) {
        if (index < 0 || index >= heap.size()) {
            throw std::out_of_range("Index out of range"); // Проверка корректности индекса
        }
        T oldValue = heap[index];
        heap[index] = newValue; // Обновляем значение
        if (comp(newValue, oldValue)) {
            siftUp(index); // Просеиваем вверх, если новый приоритет выше
        } else {
            siftDown(index); // Просеиваем вниз, если новый приоритет ниже
        }
    }

    // Вывод кучи (для отладки)
    // Сложность: O(n)
    void printHeap() const {
        for (const T& value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Получение размера кучи
    // Сложность: O(1)
    size_t size() const {
        return heap.size();
    }
};

// Функция для отображения меню
void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Вставить элемент\n";
    std::cout << "2. Извлечь корневой элемент\n";
    std::cout << "3. Просмотреть корневой элемент\n";
    std::cout << "4. Удалить элемент по индексу\n";
    std::cout << "5. Изменить приоритет элемента\n";
    std::cout << "6. Вывести кучу\n";
    std::cout << "7. Выйти\n";
    std::cout << "Выберите операцию: ";
}

int main() {
    int heapTypeChoice;
    std::cout << "Выберите тип кучи:\n";
    std::cout << "1. Max-Heap\n";
    std::cout << "2. Min-Heap\n";
    std::cout << "Ваш выбор: ";
    std::cin >> heapTypeChoice;

    if (heapTypeChoice == 1) {
        Heap<int, std::less<int>> heap; // Max-heap
        int choice, value, index;

        while (true) {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
                case 1: // Вставка элемента
                    std::cout << "Введите значение для вставки: ";
                    std::cin >> value;
                    heap.insert(value);
                    std::cout << "Элемент " << value << " вставлен.\n";
                    break;

                case 2: // Извлечение корневого элемента
                    try {
                        value = heap.extractTop();
                        std::cout << "Извлечённый элемент: " << value << "\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 3: // Просмотр корневого элемента
                    try {
                        value = heap.peek();
                        std::cout << "Корневой элемент: " << value << "\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 4: // Удаление элемента по индексу
                    std::cout << "Введите индекс элемента для удаления: ";
                    std::cin >> index;
                    try {
                        heap.deleteElement(index);
                        std::cout << "Элемент с индексом " << index << " удалён.\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 5: // Изменение приоритета элемента
                    std::cout << "Введите индекс элемента и новое значение: ";
                    std::cin >> index >> value;
                    try {
                        heap.changePriority(index, value);
                        std::cout << "Приоритет элемента изменён.\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 6: // Вывод кучи
                    std::cout << "Текущая куча: ";
                    heap.printHeap();
                    break;

                case 7: // Выход
                    std::cout << "Выход из программы.\n";
                    return 0;

                default:
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    } else if (heapTypeChoice == 2) {
        Heap<int, std::greater<int>> heap; // Min-heap
        int choice, value, index;

        while (true) {
            displayMenu();
            std::cin >> choice;

            switch (choice) {
                case 1: // Вставка элемента
                    std::cout << "Введите значение для вставки: ";
                    std::cin >> value;
                    heap.insert(value);
                    std::cout << "Элемент " << value << " вставлен.\n";
                    break;

                case 2: // Извлечение корневого элемента
                    try {
                        value = heap.extractTop();
                        std::cout << "Извлечённый элемент: " << value << "\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 3: // Просмотр корневого элемента
                    try {
                        value = heap.peek();
                        std::cout << "Корневой элемент: " << value << "\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 4: // Удаление элемента по индексу
                    std::cout << "Введите индекс элемента для удаления: ";
                    std::cin >> index;
                    try {
                        heap.deleteElement(index);
                        std::cout << "Элемент с индексом " << index << " удалён.\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 5: // Изменение приоритета элемента
                    std::cout << "Введите индекс элемента и новое значение: ";
                    std::cin >> index >> value;
                    try {
                        heap.changePriority(index, value);
                        std::cout << "Приоритет элемента изменён.\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << "Ошибка: " << e.what() << "\n";
                    }
                    break;

                case 6: // Вывод кучи
                    std::cout << "Текущая куча: ";
                    heap.printHeap();
                    break;

                case 7: // Выход
                    std::cout << "Выход из программы.\n";
                    return 0;

                default:
                    std::cout << "Неверный выбор. Попробуйте снова.\n";
            }
        }
    } else {
        std::cout << "Неверный выбор типа кучи.\n";
    }

    return 0;
}
