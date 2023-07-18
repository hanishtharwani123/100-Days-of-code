// 25. Trapping Rain Water
#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    water += maxLeft - height[left];

                left++;
            } else {
                if (height[right] >= maxRight)
                    maxRight = height[right];
                else
                    water += maxRight - height[right];

                right--;
            }
        }

        return water;
    }
};

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    int trappedWater = solution.trap(height);
    std::cout << "Trapped Water: " << trappedWater << std::endl;
    return 0;
}
