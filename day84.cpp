// 84.  Search a 2D Matrix II
#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        int row = 0;
        int col = cols - 1;

        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                // If the current element is less than the target, move down in the matrix
                ++row;
            } else {
                // If the current element is greater than the target, move left in the matrix
                --col;
            }
        }

        return false;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    int target1 = 5;
    int target2 = 20;

    bool result1 = solution.searchMatrix(matrix, target1);
    bool result2 = solution.searchMatrix(matrix, target2);

    std::cout << "Target 1 found: " << std::boolalpha << result1 << std::endl;
    std::cout << "Target 2 found: " << std::boolalpha << result2 << std::endl;

    return 0;
}
