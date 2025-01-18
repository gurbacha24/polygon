#include <iostream>
#include <cstdlib>
#include <ctime>

// асимпоттика: O(n+k) n -- количество элементов массива, k -- максимальный элемент (и количество элементов массива подсчёта)
void countingSort(int arr[], int n) {
    // Найти максимальный элемент в массиве
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Создать массив подсчёта и инициализировать его нулями
    int* count = new int[max + 1]();

    // Заполнить массив подсчёта
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Восстановить отсортированный массив из массива подсчёта
    int index = 0;
    for (int i = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

int main() {
    int N;
    std::cout << "Enter the number of elements: ";
    std::cin >> N;

    int* arr = new int[N];
    srand(static_cast<unsigned int>(time(0)));

    // генерация случайных чисел от 0 до 7999
    std::cout << "The input array:";
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 8000;
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    countingSort(arr, N);

    std::cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}