// 60. Word Break
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.length();
        vector<bool> dp(n + 1, false); // dp[i] indicates if substring ending at index i can be segmented
        
        dp[0] = true; // Empty string can always be segmented
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break; // No need to check further if we found a valid segmentation
                }
            }
        }
        
        return dp[n];
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    Solution solution;
    bool result = solution.wordBreak(s, wordDict);
    
    cout << "Result: " << (result ? "true" : "false") << endl;

    return 0;
}
