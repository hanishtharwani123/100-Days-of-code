// 35. Unique Paths
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Initialize a 2D grid to store the number of paths at each cell
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: there is only one way to reach the cells in the first row and first column
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;

        // Calculate the number of paths for each cell
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // Return the number of paths to the bottom-right corner
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 7;
    Solution sol;

    int numPaths = sol.uniquePaths(m, n);

    cout << "Number of Unique Paths: " << numPaths << endl;

    return 0;
}
