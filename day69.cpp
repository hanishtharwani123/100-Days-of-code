// 69. Majority Element
#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int majority = nums[0]; // Initialize the majority candidate
        int count = 1;         // Initialize the count of the majority candidate

        // Traverse the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                // If count becomes zero, update the majority candidate
                majority = nums[i];
                count = 1;
            } else if (nums[i] == majority) {
                // If the current element is equal to the majority candidate, increment the count
                count++;
            } else {
                // If the current element is different from the majority candidate, decrement the count
                count--;
            }
        }

        return majority;
    }
};

int main() {
    std::vector<int> nums = {3, 2, 3};
    Solution solution;

    int result = solution.majorityElement(nums);

    std::cout << "Majority Element: " << result << std::endl;

    return 0;
}
