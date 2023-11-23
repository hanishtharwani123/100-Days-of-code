// 96. Permutation in String
#include <string>
#include <unordered_map>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        // Create frequency maps for both strings
        std::unordered_map<char, int> s1Freq, windowFreq;

        for (char ch : s1) {
            s1Freq[ch]++;
        }

        // Initialize the frequency map for the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            windowFreq[s2[i]]++;
        }

        // Check if the first window is a permutation
        if (windowFreq == s1Freq) {
            return true;
        }

        // Iterate through the rest of the string using a sliding window
        for (int i = s1.length(); i < s2.length(); ++i) {
            // Remove the leftmost character from the window
            char leftChar = s2[i - s1.length()];
            if (windowFreq[leftChar] == 1) {
                windowFreq.erase(leftChar);
            } else {
                windowFreq[leftChar]--;
            }

            // Add the current character to the window
            windowFreq[s2[i]]++;

            // Check if the current window is a permutation
            if (windowFreq == s1Freq) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    bool result = solution.checkInclusion(s1, s2);

    return 0;
}
