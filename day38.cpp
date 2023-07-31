// 38. Edit Distance
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();

        // Initialize the dynamic programming table with (m+1) rows and (n+1) columns
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // Fill up the first row and first column
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }

        // Fill up the remaining cells in the dp table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    Solution solution;
    std::string word1 = "horse";
    std::string word2 = "ros";
    int result = solution.minDistance(word1, word2);
    std::cout << "Minimum number of operations: " << result << std::endl;
    return 0;
}
