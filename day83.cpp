// 83. Sliding Window Maximum
#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove elements that are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // Add the maximum element in the current window to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    std::vector<int> result = solution.maxSlidingWindow(nums, k);

    // Print the result
    std::cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i];
        if (i < result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
