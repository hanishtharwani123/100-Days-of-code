#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int left = 0;
        int right = 0;
        unordered_set<char> uniqueChars;

        while (right < n) {
            if (uniqueChars.find(s[right]) == uniqueChars.end()) {
                uniqueChars.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                uniqueChars.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    string input = "abcabcbb";
    int length = solution.lengthOfLongestSubstring(input);
    cout << "Length of the longest substring without repeating characters: " << length << endl;
    return 0;
}
