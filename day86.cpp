// 86. Find the Duplicate Number
#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        // Phase 1: Detect if there's a cycle in the array
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 3, 4, 2, 2};

    int result = solution.findDuplicate(nums);

    std::cout << "Duplicate number: " << result << std::endl;

    return 0;
}
