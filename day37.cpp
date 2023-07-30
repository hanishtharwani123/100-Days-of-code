// 37. Climbing Stairs
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    Solution solution;
    int distinctWays = solution.climbStairs(n);

    std::cout << "Number of distinct ways to climb the stairs: " << distinctWays << std::endl;

    return 0;
}
