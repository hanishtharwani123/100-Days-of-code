// 33. Jump Game
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (i > farthest) {
                // If the current index is beyond the farthest reachable index,
                // then we cannot proceed further.
                return false;
            }

            // Update the farthest reachable index from the current position.
            farthest = max(farthest, i + nums[i]);

            // If the farthest index is already beyond or at the last index,
            // we can reach the end of the array.
            if (farthest >= n - 1) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Output: " << (sol.canJump(nums) ? "true" : "false") << endl; // Output: true

    return 0;
}
