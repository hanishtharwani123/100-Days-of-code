// 93. Find All Anagrams in a String

#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> result;
        int sLen = s.length(), pLen = p.length();

        if (sLen < pLen) {
            return result;
        }

        std::unordered_map<char, int> pFreq, windowFreq;

        // Initialize the frequency map for pattern p
        for (char ch : p) {
            pFreq[ch]++;
        }

        // Initialize the frequency map for the first window in s
        for (int i = 0; i < pLen; ++i) {
            windowFreq[s[i]]++;
        }

        // Check if the first window is an anagram
        if (windowFreq == pFreq) {
            result.push_back(0);
        }

        // Iterate through the rest of the string using a sliding window
        for (int i = pLen; i < sLen; ++i) {
            // Remove the leftmost character from the window
            char leftChar = s[i - pLen];
            if (windowFreq[leftChar] == 1) {
                windowFreq.erase(leftChar);
            } else {
                windowFreq[leftChar]--;
            }

            // Add the current character to the window
            windowFreq[s[i]]++;

            // Check if the current window is an anagram
            if (windowFreq == pFreq) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string s = "cbaebabacd";
    std::string p = "abc";
    std::vector<int> result = solution.findAnagrams(s, p);

    return 0;
}
