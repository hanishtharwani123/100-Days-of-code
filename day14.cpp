// 14. Generate Parentheses

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& result, string current, int open, int close, int n) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(result, current + '(', open + 1, close, n);
        }

        if (close < open) {
            backtrack(result, current + ')', open, close + 1, n);
        }
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> parentheses = solution.generateParenthesis(n);

    cout << "Combinations of well-formed parentheses for n = " << n << ":" << endl;
    for (const string& p : parentheses) {
        cout << p << endl;
    }

    return 0;
}
