// 85. Move Zeroes
#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int nonZeroIndex = 0;

        // Move non-zero elements to the front
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        // Fill the remaining positions with zeros
        while (nonZeroIndex < nums.size()) {
            nums[nonZeroIndex++] = 0;
        }
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {0, 1, 0, 3, 12};

    std::cout << "Original array: [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    solution.moveZeroes(nums);

    std::cout << "Array after moving zeroes: [";
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
