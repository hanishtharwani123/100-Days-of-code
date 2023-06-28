#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0; 
        int right = height.size() - 1; 
        int maxArea = 0; 

        while (left < right) {
            
            int currentArea = min(height[left], height[right]) * (right - left);

            maxArea = max(maxArea, currentArea);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxArea;
    }
};

int main() {
    vector<int> height = { 1, 1 };
    Solution solution;
    int maxWater = solution.maxArea(height);
    cout << "Maximum amount of water that can be stored: " << maxWater << endl;

    return 0;
}
