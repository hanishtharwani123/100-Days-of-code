// 21. Find First and Last Position of Element in Sorted Array
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        
        return {first, last};
    }
    
private:
    int findFirst(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] >= target) {
                right = mid - 1;
                if (nums[mid] == target)
                    result = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] <= target) {
                left = mid + 1;
                if (nums[mid] == target)
                    result = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = solution.searchRange(nums, target);

    cout << "First position: " << result[0] << endl;
    cout << "Last position: " << result[1] << endl;

    return 0;
}
