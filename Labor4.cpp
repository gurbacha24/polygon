#include <iostream>
#include <vector>

// функция для вычисления максимальной стоимости рюкзака
int backpack(const std::vector<std::pair<int, int>>& items, int weight_limit, std::vector<int>& selected_items) {
    int n = items.size();
    int max_value = 0;

    // перебор всех комбинаций от 0 до 2^n - 1
    for (int combination = 0; combination < (1 << n); ++combination) {
        /*
        O(2^N) (перебор 0...00 ни один предмет не в комбинации,
        0...01 только 1й, 0...10 только 2й, ...,
        1...11 все предметы в комбинации)
        */
        int total_weight = 0;
        int total_value = 0;
        std::vector<int> current_selection;

        // проверка какие предметы включены в текущую комбинацию
        for (int i = 0; i < n; ++i) { // O(N)
            if (combination & (1 << i)) { // если итый предмет включён  // O(1)
                total_weight += items[i].first; // добавляем его вес
                total_value += items[i].second; // добавляем его стоимость
                current_selection.push_back(i + 1); // добавляем его номер в выбор
            }
        }

        // если вес не превышает лимит и стоимость больше текущей максимальной
        if (total_weight <= weight_limit && total_value > max_value) { // O(1)
            max_value = total_value; // обновляем максимальную стоимость
            selected_items = current_selection; // сохраняем выбранные предметы
        }
    }

    return max_value;
}

int main() { // O(N)
    // входные данные: парочки (вес, стоимость)
    std::vector<std::pair<int, int>> items = { {2, 3}, {3, 4}, {4, 5} };
    int weight_limit = 5;

    // переменные для результата
    std::vector<int> selected_items;
    int max_value = backpack(items, weight_limit, selected_items);

    // вывод результата
    std::cout << "max price: " << max_value << "\n";
    std::cout << "chosen items: ";
    for (int item : selected_items) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
// сложность O(2^N * N) внутренний цикл -- N, внешний -- 2^N ^_^
// в лучшем случае O(N), в среднем O(2^N * N)
