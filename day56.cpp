// 56. Longest Consecutive Sequence
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestSequence = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) { // Start of a potential sequence
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestSequence = max(longestSequence, currentStreak);
            }
        }

        return longestSequence;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    int longestSequence = solution.longestConsecutive(nums);
    
    cout << "The longest consecutive sequence length is: " << longestSequence << endl;

    return 0;
}
