// 54. Best Time to Buy and Sell Stock

#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = INT_MAX; // Initialize minimum price to a large value
        int maxProfit = 0; // Initialize maximum profit to 0
        
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i]; // Update minimum price if a smaller price is encountered
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice; // Update maximum profit if a better selling opportunity is found
            }
        }
        
        return maxProfit;
    }
};

int main() {
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solution;
    int result = solution.maxProfit(prices);
    std::cout << "Maximum Profit: " << result << std::endl;
    return 0;
}
