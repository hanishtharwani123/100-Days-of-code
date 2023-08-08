// 36. Minimum Path Sum
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Create a DP table to store the minimum path sum for each cell
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        // Initialize the first row and first column of the DP table
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Calculate the minimum path sum for each cell
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = grid[i][j] + std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // The bottom-right cell of the DP table will contain the minimum path sum
        return dp[m - 1][n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution solution;
    int result = solution.minPathSum(grid);
    std::cout << "Minimum Path Sum: " << result << std::endl;
    return 0;
}
