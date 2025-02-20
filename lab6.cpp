#include <iostream>

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0; // O(1)
        long long factor = 1; // O(1)
        
        while (factor <= n) { // O(log n), так как factor увеличивается в 10 раз на каждой итерации
            long long lower = n - (n / factor) * factor; // O(1) - вычисление остатка справа от текущей цифры
            long long curr = (n / factor) % 10; // O(1) - текущая цифра
            long long higher = n / (factor * 10); // O(1) - часть числа слева от текущей цифры
            
            // Подсчёт количества единиц в текущем разряде
            if (curr == 0) { 
                count += higher * factor; // O(1)
            } else if (curr == 1) { 
                count += higher * factor + lower + 1; // O(1)
            } else { 
                count += (higher + 1) * factor; // O(1)
            }

            factor *= 10; // O(1) - переход к следующему разряду
        }

        return count; // O(1)
    }
};

int main() {
    int n;
    std::cin >> n; // O(1)
    Solution solution;
    std::cout << solution.countDigitOne(n) << std::endl; // O(1)
    return 0;
}
