// 31. Maximum Subarray
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }

        return max_sum;
    }
};

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution solution;
    int result = solution.maxSubArray(nums);
    std::cout << "Maximum Subarray Sum: " << result << std::endl;
    return 0;
}
