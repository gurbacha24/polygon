#include <iostream>
#include <cstdlib>
#include <ctime>

// асимптотика~~
// лучший случай: O(n) — массив уже отсортирован, надо пройтись по нему только 1 раз
// средний/худщий случай: O(n^2) — случайное расположение элементов или в обратном порядке
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // обмен
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    bubbleSort(arr, N);

    std::cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
