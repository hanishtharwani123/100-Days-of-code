//5. Longest Palindromic Substring

#include <iostream>
#include <string>
#include <cstring> // Added for memset function

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2)
            return s;

        int start = 0, maxLength = 1;

        // Dynamic programming table to store the states of palindromic substrings
        bool dp[n][n];
        memset(dp, false, sizeof(dp));

        // Every single character is a palindrome
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check for substrings of length greater than 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};

int main() {
    Solution solution;
    string s = "babad";
    string longestPalindrome = solution.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << longestPalindrome << endl;
    return 0;
}
