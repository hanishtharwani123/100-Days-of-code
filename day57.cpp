// 57.  Palindrome Partitioning
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string s, int start, vector<string>& current, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.length(); ++end) {
            if (isPalindrome(s, start, end)) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
};

int main() {
    Solution solution;
    string input = "aab";
    vector<vector<string>> partitions = solution.partition(input);

    cout << "Palindrome partitions of \"" << input << "\":" << endl;
    for (const auto& partition : partitions) {
        cout << "[";
        for (size_t i = 0; i < partition.size(); ++i) {
            cout << "\"" << partition[i] << "\"";
            if (i < partition.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}
