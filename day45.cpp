// 45. Largest Rectangle in Histogram
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st; // Stack to store indices of bars
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    Solution solution;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int result = solution.largestRectangleArea(heights);
    cout << "Largest Rectangle Area: " << result << endl;
    
    return 0;
}
