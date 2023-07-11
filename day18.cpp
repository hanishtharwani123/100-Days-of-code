// 18. NEXT PERMUTATION
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first pair from the right where nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            int j = n - 1;

            // Find the first element from the right that is greater than nums[i]
            while (j >= 0 && nums[j] <= nums[i])
                j--;

            // Swap nums[i] and nums[j]
            swap(nums[i], nums[j]);
        }

        // Reverse the subarray nums[i+1:]
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
