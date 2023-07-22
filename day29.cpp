#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Create a hash map to store the anagrams
        std::unordered_map<std::string, std::vector<std::string>> anagramMap;

        // Iterate through each word in the input array
        for (const std::string& word : strs) {
            // Sort the word to find its anagram representation
            std::string sortedWord = word;
            std::sort(sortedWord.begin(), sortedWord.end());

            // Add the word to its corresponding anagram group in the hash map
            anagramMap[sortedWord].push_back(word);
        }

        // Convert the hash map values to the final result vector
        std::vector<std::vector<std::string>> result;
        for (const auto& pair : anagramMap) {
            result.push_back(pair.second);
        }

        return result;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};
    std::vector<std::vector<std::string>> result = solution.groupAnagrams(strs);

    // Print the output
    for (const auto& group : result) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
