#include <iostream>
#include <cstdlib>
#include <ctime>

// выбор опорного элемента (pivot) и перемещение элементов меньше него влево, а больше него вправо
// аааасимптотика
// Лучший случай: O(n) — элементы делятся поровну.
// Худший случай: O(n^2) — массив уже отсортирован или все элементы равны.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // обмен
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // обмен опорного элемента
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// рекурсивная сортировка массива. (разделение массива на части вокруг опорного элемента)
// асимптотика
// Лучший случай: O(n log n) — элементы делятся на две равные части.
// Средний случай: O(n log n) — элементы делятся примерно поровну.
// Худший случай: O(n^2) — массив уже отсортирован или элементы равны.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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

    quickSort(arr, 0, N - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}