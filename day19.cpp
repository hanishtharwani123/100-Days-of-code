// 19. Longest Valid Parentheses
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1); // Push -1 as the base index

        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i); // Push the current index as the new base
                } else {
                    maxLen = max(maxLen, i - stk.top()); // Calculate the length of the valid parentheses substring
                }
            }
        }

        return maxLen;
    }
};

int main() {
    Solution solution;
    string input = "(()";
    int result = solution.longestValidParentheses(input);
    cout << "Length of the longest valid parentheses substring: " << result << endl;

    return 0;
}
