#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

/*
Алгоритм сортировки Bozosort (Сортировка клоуна Бозо)
Сложность:
в лучшем случае -- O(n);
в среднем случае -- O(n * n!).
в худшем случае сортировка может вообще не закончиться.
Память -- O(n * n!).
*/

// Функция для выполнения Bozosort
void bozosort(std::vector<int>& arr) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<size_t> dist(0, arr.size() - 1);

    while (!std::is_sorted(arr.begin(), arr.end())) {
        // Меняем местами два случайных элемента
        size_t i = dist(g), j = dist(g);
        std::swap(arr[i], arr[j]);
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
    bozosort(arr);

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
