#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());
        std::unordered_map<int, std::vector<std::string>> memo;
        return dfs(s, 0, wordSet, memo);
    }

private:
    std::vector<std::string> dfs(const std::string& s, int start, std::unordered_set<std::string>& wordSet, std::unordered_map<int, std::vector<std::string>>& memo) {
        if (memo.find(start) != memo.end()) {
            return memo[start];
        }
        if (start == s.size()) {
            return {""};
        }
        std::vector<std::string> result;
        for (int end = start + 1; end <= s.size(); ++end) {
            std::string word = s.substr(start, end - start);
            if (wordSet.count(word)) {
                std::vector<std::string> subSentences = dfs(s, end, wordSet, memo);
                for (const std::string& sub : subSentences) {
                    if (sub.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sub);
                    }
                }
            }
        }
        memo[start] = result;
        return result;
    }
};

