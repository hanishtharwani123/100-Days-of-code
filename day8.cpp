// 8. longest Common Prefix
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 
        if (strs.size() == 1) return strs[0]; 
        string lcp = strs[0]; 

        for (int i = 1; i < strs.size() && !lcp.empty(); ++i) {
            const string& current = strs[i];
            int j = 0;
            while (j < lcp.length() && j < current.length() && lcp[j] == current[j]) {
                ++j;
            }
            lcp = lcp.substr(0, j); 
        }

        return lcp;
    }
};
int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
