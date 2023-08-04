// 42. Minimum Window Substring
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        // Create frequency maps for characters in strings s and t
        std::unordered_map<char, int> required_chars;
        for (char c : t) {
            required_chars[c]++;
        }

        std::unordered_map<char, int> window_chars;
        int left = 0; // Left pointer of the sliding window
        int min_window_len = m + 1; // Use m + 1 as the initial value for min_window_len
        int min_window_start = 0;
        int chars_to_match = required_chars.size(); // Number of distinct characters to match

        int matched_chars = 0; // Number of characters matched so far

        // Iterate through the string s with the right pointer
        for (int right = 0; right < m; right++) {
            char current_char = s[right];

            // Update the frequency of the current character in the window_chars map
            window_chars[current_char]++;

            // Check if the current character is one of the required characters and its count matches
            // the required count from string t.
            if (required_chars.find(current_char) != required_chars.end() &&
                window_chars[current_char] == required_chars[current_char]) {
                matched_chars++;
            }

            // If all required characters are matched, try to shrink the window
            while (matched_chars == chars_to_match && left <= right) {
                int window_len = right - left + 1;

                // If the current window is smaller than the minimum window found so far, update the minimum window
                if (window_len < min_window_len) {
                    min_window_len = window_len;
                    min_window_start = left;
                }

                char left_char = s[left];
                // Remove the left character from the window and update the frequency map
                window_chars[left_char]--;

                // If the left character is one of the required characters and its count becomes less than
                // the required count from string t, decrease the matched_chars count.
                if (required_chars.find(left_char) != required_chars.end() &&
                    window_chars[left_char] < required_chars[left_char]) {
                    matched_chars--;
                }

                left++; // Move the left pointer to shrink the window
            }
        }

        // Check if a valid window was found
        if (min_window_len == m + 1) {
            return "";
        }

        // Extract the minimum window substring from s
        return s.substr(min_window_start, min_window_len);
    }
};

int main() {
    Solution solution;
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    std::string result = solution.minWindow(s, t);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
