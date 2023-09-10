// 70. Rotate Array
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Calculate effective rotation amount
        
        // Create a temporary array to store elements
        vector<int> temp(k);
        
        // Copy the last k elements to the temporary array
        for (int i = n - k, j = 0; i < n; ++i, ++j) {
            temp[j] = nums[i];
        }
        
        // Shift the remaining elements to the right by k steps
        for (int i = n - k - 1; i >= 0; --i) {
            nums[i + k] = nums[i];
        }
        
        // Copy elements from the temporary array back to the beginning
        for (int i = 0; i < k; ++i) {
            nums[i] = temp[i];
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    solution.rotate(nums, k);

    cout << "Rotated Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
