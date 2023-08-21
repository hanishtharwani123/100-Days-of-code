// 58. Single Number
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num; // XOR all elements
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 2, 1};
    int single = solution.singleNumber(nums);
    cout << "The single number is: " << single << endl;
    return 0;
}
