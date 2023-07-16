// 23. Combination Sum
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], i, combination, result);
                combination.pop_back();
            }
        }
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> combinations = solution.combinationSum(candidates, target);

    // Print the combinations
    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
