#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        using Element = std::pair<int, std::pair<int, int>>;
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap; // O(1)
        int maxValue = std::numeric_limits<int>::min(); // O(1)
        int rangeStart = 0, rangeEnd = std::numeric_limits<int>::max(); // O(1)

        // Инициализируем minHeap начальными элементами из каждого списка
        for (int i = 0; i < nums.size(); i++) { // O(K log K), где K - количество списков
            minHeap.push({nums[i][0], {i, 0}}); // O(log K)
            maxValue = std::max(maxValue, nums[i][0]); // O(1)
        }

        // Основной цикл: извлекаем минимум и добавляем следующий элемент из того же списка
        while (!minHeap.empty()) { // O(N log K), где N - общее число элементов во всех списках
            auto [minValue, pos] = minHeap.top(); // O(1)
            minHeap.pop(); // O(log K)
            int listIndex = pos.first, elementIndex = pos.second; // O(1)

            // Обновляем диапазон, если нашли более узкий
            if (maxValue - minValue < rangeEnd - rangeStart) { // O(1)
                rangeStart = minValue;
                rangeEnd = maxValue;
            }

            // Если достигнут конец одного из списков, выходим
            if (elementIndex + 1 == nums[listIndex].size()) break; // O(1)

            // Добавляем следующий элемент из того же списка в minHeap
            int nextValue = nums[listIndex][elementIndex + 1]; // O(1)
            minHeap.push({nextValue, {listIndex, elementIndex + 1}}); // O(log K)
            maxValue = std::max(maxValue, nextValue); // O(1)
        }

        return {rangeStart, rangeEnd}; // O(1)
    }
};
