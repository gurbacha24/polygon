#include <iostream>
#include <vector>
#include <chrono>

int n, W, bestCost = 0;
std::vector<std::pair<int, int>> items;
std::vector<int> best, cur;

/*
Рекурсивная функция обхода в глубину для перебора всех возможных комбинаций предметов.
(включён/не включён в комбинацию: 0...00, 0...01, ..., 1...11)
Сложность O(2^N), N -- количество предметов
То есть для каждого из N предметов каждый раз выбор -- взять его или не взять
*/
void dfs(int i, int w, int c) {
    if (i == n) {
        if (c > bestCost) {
            bestCost = c;
            best = cur;
        }
        return;
    }
    dfs(i + 1, w, c);
    if (w + items[i].first <= W) {
        cur.push_back(items[i].first);
        dfs(i + 1, w + items[i].first, c + items[i].second);
        cur.pop_back();
    }
}

int main() {
    // Начало измерения времени
    auto start = std::chrono::high_resolution_clock::now();

    // Ввод данных
    std::cin >> n;
    items.resize(n);
    
    // Сложность O(N), N -- количество предметов
    for (int i = 0; i < n; i++) {
        // Вес и стоимость каждого предмета
        std::cin >> items[i].first >> items[i].second;
    }
    std::cin >> W;
    
    // Запуск рекурсивного перебора
    dfs(0, 0, 0);
    
    // Вывод данных
    std::cout << "[";
    // Сложность O(N), N -- количество предметов в лучшей комбинации
    for (int i = 0; i < best.size(); i++) {
        std::cout << best[i] << (i + 1 < best.size() ? "," : "");
    }
    std::cout << "] (The best cost " << bestCost << ")\n";

    // Конец измерения времени
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Вывод времени выполнения
    std::cout << "Time taken: " << elapsed.count() << " seconds\n";

    return 0;
}
