#include<iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> result;
        string currentCombination;

        generateCombinations(digits, 0, digitToLetters, currentCombination, result);

        return result;
    }

private:
    void generateCombinations(const string& digits, int index, const unordered_map<char, string>& digitToLetters,
                              string& currentCombination, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        if (digitToLetters.find(currentDigit) != digitToLetters.end()) {
            string letters = digitToLetters.at(currentDigit);
            for (char letter : letters) {
                currentCombination.push_back(letter);
                generateCombinations(digits, index + 1, digitToLetters, currentCombination, result);
                currentCombination.pop_back();
            }
        }
    }
};
int main() {
    Solution sol;
    string digits = "23";
    vector<string> result = sol.letterCombinations(digits);
    for (const string& combination : result) {
        cout << combination << " ";
    }
    cout << endl;
    return 0;
}