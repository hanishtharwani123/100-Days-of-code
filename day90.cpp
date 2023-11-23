// 90. Top K Frequent Elements
#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // Create a hash map to count the frequency of each element
        std::unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Create a min heap to store the k most frequent elements
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;

        // Iterate through the frequency map and add elements to the min heap
        for (auto& entry : frequencyMap) {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // Extract the elements from the min heap
        std::vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Reverse the result vector to get the elements in descending order of frequency
        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    std::vector<int> result = solution.topKFrequent(nums, k);

    return 0;
}
