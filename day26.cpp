// 26. Jump Game II
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int end = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = std::max(farthest, i + nums[i]);

            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    std::vector<int> nums = {2, 3, 1, 1, 4};
    Solution solution;
    int minJumps = solution.jump(nums);

    std::cout << "Minimum number of jumps: " << minJumps << std::endl;

    return 0;
}
