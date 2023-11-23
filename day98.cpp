// 98. Daily Temperatures
#include <vector>
#include <stack>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n, 0);
        std::stack<int> indexStack;

        for (int i = 0; i < n; ++i) {
            while (!indexStack.empty() && temperatures[i] > temperatures[indexStack.top()]) {
                int prevIndex = indexStack.top();
                indexStack.pop();
                result[prevIndex] = i - prevIndex;
            }
            indexStack.push(i);
        }

        return result;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    std::vector<int> result = solution.dailyTemperatures(temperatures);

    // Output the result
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}
