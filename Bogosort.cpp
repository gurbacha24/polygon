#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

/*
Алгоритм сортировки Bogosort/Monkeysort (Болотная/Обезьянья сортировка)
Сортирует путём повторяющихся перемешиек, пока перемешка не даст отсортированный массив.
Сложность:
в лучшем случае -- O(n);
в среднем случае -- O(n * n!);
в худшем случае сортировка может вообще не закончиться.
Память: O(1).
*/

// Функция для выполнения Bogosort
void bogosort(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());

    // Проверка на отсортированность
    while (!std::is_sorted(arr.begin(), arr.end())) {
        std::shuffle(arr.begin(), arr.end(), g); // Случайная перемешка массива
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 10, 11, 12, 1, 5, 111, 100};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Замеряем время
    std::clock_t start = std::clock(); // Начало замера

    // Выполняем Bogosort
    bogosort(arr);

    std::clock_t end = std::clock(); // Конец замера
    double time = double(end - start) / CLOCKS_PER_SEC; // Вычисляем время в секундах

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Time taken: " << time << " seconds" << std::endl;

    return 0;
}