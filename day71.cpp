// 71. House Robber
#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        std::vector<int> dp(n, 0); // Create an array to store the maximum money robbed up to house i
        
        dp[0] = nums[0]; // Initialize the first element
        
        // Calculate the maximum money for each house
        for (int i = 1; i < n; i++) {
            // Two options: rob the current house and add the money from two houses ago,
            // or skip the current house and take the maximum money from the previous house.
            dp[i] = std::max(dp[i - 1], nums[i] + (i >= 2 ? dp[i - 2] : 0));
        }
        
        return dp[n - 1]; // Return the maximum money robbed from all houses
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    int maxMoney = solution.rob(nums);
    std::cout << "Maximum amount of money you can rob: " << maxMoney << std::endl;
    return 0;
}
