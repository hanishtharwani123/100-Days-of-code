// 27. Permutations
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false); // To keep track of used elements
        
        backtrack(nums, used, currentPermutation, result);
        return result;
    }
    
private:
    void backtrack(const vector<int>& nums, vector<bool>& used, vector<int>& currentPermutation, vector<vector<int>>& result) {
        // Base case: if the current permutation is complete, add it to the result
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }
        
        // Iterate through the elements in nums
        for (int i = 0; i < nums.size(); ++i) {
            // If the element is not used yet, add it to the current permutation
            if (!used[i]) {
                used[i] = true;
                currentPermutation.push_back(nums[i]);
                
                // Recurse to generate the next element in the permutation
                backtrack(nums, used, currentPermutation, result);
                
                // Backtrack: remove the added element to explore other possibilities
                currentPermutation.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution solution;
    vector<vector<int>> result = solution.permute(nums);
    
    // Output the permutations
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
