// 92. Partition Equal Subset Sum
#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        // If the total sum is odd, it's not possible to partition into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;

        // dp[i][j] represents whether it's possible to reach the sum j with the first i elements
        std::vector<std::vector<bool>> dp(nums.size() + 1, std::vector<bool>(targetSum + 1, false));

        // Initialization: It's always possible to reach the sum 0
        for (int i = 0; i <= nums.size(); ++i) {
            dp[i][0] = true;
        }

        // Dynamic programming
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 1; j <= targetSum; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[nums.size()][targetSum];
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 5, 11, 5};
    bool result = solution.canPartition(nums);

    return 0;
}
