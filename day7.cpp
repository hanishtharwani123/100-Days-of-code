#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int currentVal = romanValues[s[i]];
            int nextVal = (i + 1 < n) ? romanValues[s[i + 1]] : 0;

            if (currentVal < nextVal) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::string input = "III";
    int result = solution.romanToInt(input);
    std::cout << "Output: " << result << std::endl;
    return 0;
}
