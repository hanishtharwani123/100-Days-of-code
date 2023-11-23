// 88. Longest Increasing Subsequence
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        // Initialize the dp array with all 1's (minimum length is 1)
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        // The result is the maximum value in the dp array
        return *std::max_element(dp.begin(), dp.end());
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int result = solution.lengthOfLIS(nums);

    return 0;
}
