// 89. Coin Change
#include <vector>
#include <limits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Initialize the dp array with a value greater than the maximum possible number of coins
        std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;  // Base case: no coins needed to make up amount 0

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (i - coin >= 0 && dp[i - coin] != std::numeric_limits<int>::max()) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // Check if the target amount can be made up by any combination of coins
        return (dp[amount] == std::numeric_limits<int>::max()) ? -1 : dp[amount];
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = solution.coinChange(coins, amount);

    return 0;
}
