// 12. Valid Parentheses
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else if (!st.empty() && st.top() == mapping[ch]) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;
    cout << solution.isValid("()") << endl; // Output: true
    cout << solution.isValid("()[]{}") << endl; // Output: true
    cout << solution.isValid("(]") << endl; // Output: false
    cout << solution.isValid("([)]") << endl; // Output: false
    cout << solution.isValid("{[]}") << endl; // Output: true
    return 0;
}
