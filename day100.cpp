// 100. Longest Common Subsequence
#include <vector>
#include <string>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.size();
        int n = text2.size();

        // Create a 2D array to store the lengths of common subsequences
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // Fill in the DP array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string text1 = "abcde";
    std::string text2 = "ace";
    int result = solution.longestCommonSubsequence(text1, text2);

    // Output the result
    std::cout << "Length of longest common subsequence: " << result << std::endl;

    return 0;
}
