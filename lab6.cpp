#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums) {
        using Element = std::pair<int, std::pair<int, int>>;
        std::priority_queue<Element, std::vector<Element>, std::greater<Element>> minHeap;
        int maxValue = std::numeric_limits<int>::min();
        int rangeStart = 0, rangeEnd = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], {i, 0}});
            maxValue = std::max(maxValue, nums[i][0]);
        }

        while (!minHeap.empty()) {
            auto [minValue, pos] = minHeap.top();
            minHeap.pop();
            int listIndex = pos.first, elementIndex = pos.second;

            if (maxValue - minValue < rangeEnd - rangeStart) {
                rangeStart = minValue;
                rangeEnd = maxValue;
            }

            if (elementIndex + 1 == nums[listIndex].size()) break;

            int nextValue = nums[listIndex][elementIndex + 1];
            minHeap.push({nextValue, {listIndex, elementIndex + 1}});
            maxValue = std::max(maxValue, nextValue);
        }

        return {rangeStart, rangeEnd};
    }
};
