// 4. Median of Two Sorted Arrays

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge the two sorted arrays
        vector<int> merged;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }
        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }
        // Calculate the median
        int size = merged.size();
        if (size % 2 == 0) {
            return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
        } else {
            return merged[size / 2];
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = solution.findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;
    return 0;
}
