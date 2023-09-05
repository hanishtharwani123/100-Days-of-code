// 65. Maximum Product Subarray
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int max_product = nums[0]; // To store the maximum product ending at the current index
        int min_product = nums[0]; // To store the minimum product ending at the current index
        int result = nums[0];      // To store the maximum product overall
        
        for (int i = 1; i < n; i++) {
            // Swap max_product and min_product if nums[i] is negative
            if (nums[i] < 0) {
                std::swap(max_product, min_product);
            }
            
            // Update max_product and min_product for the current index
            max_product = std::max(nums[i], max_product * nums[i]);
            min_product = std::min(nums[i], min_product * nums[i]);
            
            // Update the overall result
            result = std::max(result, max_product);
        }
        
        return result;
    }
};

int main() {
    // Example usage
    std::vector<int> nums = {2, 3, -2, 4};
    Solution solution;
    int maxProductResult = solution.maxProduct(nums);
    std::cout << "Maximum Product Subarray: " << maxProductResult << std::endl;
    
    return 0;
}
