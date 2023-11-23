// 82. Product of Array Except Self
#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> result(n, 1);

        // Compute the product of elements to the left
        int leftProduct = 1;
        for (int i = 0; i < n; ++i) {
            result[i] *= leftProduct;
            leftProduct *= nums[i];
        }

        // Compute the product of elements to the right
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; --i) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = solution.productExceptSelf(nums);

    // Print the result
    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
