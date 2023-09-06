// 66. Find Minimum in Rotated Sorted Array
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution solution;

    int minElement = solution.findMin(nums);

    cout << "Minimum element: " << minElement << endl;

    return 0;
}
