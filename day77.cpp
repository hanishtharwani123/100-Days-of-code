// 77. Kth Largest Element in an Array
#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Create a min-heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Populate the min-heap with the first k elements
        for (int i = 0; i < k; ++i) {
            minHeap.push(nums[i]);
        }

        // For the remaining elements, if an element is larger than the smallest element in the heap, replace it
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > minHeap.top()) {
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }

        // The top of the min-heap now contains the kth largest element
        return minHeap.top();
    }
};

int main() {
    // Example usage
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    Solution solution;
    int result = solution.findKthLargest(nums, k);

    std::cout << "Kth largest element: " << result << std::endl;

    return 0;
}
