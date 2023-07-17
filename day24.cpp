// 24. First Missing Positive
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Remove non-positive numbers and numbers greater than n
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Step 2: Find the first missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // Step 3: All positive integers from 1 to n are present, so the smallest missing positive is n + 1
        return n + 1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 0};
    int result = solution.firstMissingPositive(nums);
    cout << "Smallest missing positive integer: " << result << endl;
    return 0;
}
