// 41. Sort Colors
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0; // pointer for the left boundary of white elements (0s)
        int right = n - 1; // pointer for the right boundary of white elements (2s)
        int current = 0; // pointer for the current element being processed

        while (current <= right) {
            if (nums[current] == 0) {
                // If the current element is 0, swap it with the left boundary
                swap(nums[current], nums[left]);
                // Move the left boundary and the current pointer one step to the right
                left++;
                current++;
            } else if (nums[current] == 2) {
                // If the current element is 2, swap it with the right boundary
                swap(nums[current], nums[right]);
                // Move the right boundary one step to the left
                right--;
            } else {
                // If the current element is 1, leave it in place and move the current pointer one step to the right
                current++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.sortColors(nums);

    cout << "Output: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
