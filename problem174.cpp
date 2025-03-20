#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        if (m == 0) return 1;
        int n = dungeon[0].size();
        if (n == 0) return 1;
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        dp[m-1][n-1] = std::max(1, 1 - dungeon[m-1][n-1]);
        
        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if (i == m-1 && j == n-1) {
                    continue;
                }
                
                int min_next = INT_MAX;
                if (i + 1 < m) {
                    min_next = std::min(min_next, dp[i+1][j]);
                }
                if (j + 1 < n) {
                    min_next = std::min(min_next, dp[i][j+1]);
                }
                
                dp[i][j] = std::max(1, min_next - dungeon[i][j]);
            }
        }
        
        return dp[0][0];
    }
};

