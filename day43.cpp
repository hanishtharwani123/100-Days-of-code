// 43. Subsets
#include <iostream>
#include <vector>

class Solution {
public:
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& currentSubset, std::vector<std::vector<int>>& result) {
        // Add the current subset to the result
        result.push_back(currentSubset);
        
        // Explore all possibilities by adding the remaining elements to the current subset
        for (int i = start; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);
            backtrack(nums, i + 1, currentSubset, result);
            currentSubset.pop_back();
        }
    }
    
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentSubset;
        
        backtrack(nums, 0, currentSubset, result);
        
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 2, 3};
    std::vector<std::vector<int>> result = solution.subsets(nums);

    // Output the result
    for (const auto& subset : result) {
        std::cout << "[";
        for (size_t i = 0; i < subset.size(); ++i) {
            std::cout << subset[i];
            if (i < subset.size() - 1)
                std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
