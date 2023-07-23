// 30. N-Queens
#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<std::string> board(n, std::string(n, '.')); // Initialize the empty board

        solveNQueensUtil(solutions, board, 0, n);

        return solutions;
    }

private:
    void solveNQueensUtil(std::vector<std::vector<std::string>>& solutions, std::vector<std::string>& board, int row, int n) {
        if (row == n) {
            // If all queens are placed, add the current board configuration to the solutions.
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q'; // Place the queen
                solveNQueensUtil(solutions, board, row + 1, n); // Recur for the next row
                board[row][col] = '.'; // Backtrack and try other possibilities
            }
        }
    }

    bool isValid(const std::vector<std::string>& board, int row, int col, int n) {
        // Check if there is no queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check if there is no queen in the upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check if there is no queen in the upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n = 4;
    Solution sol;
    std::vector<std::vector<std::string>> solutions = sol.solveNQueens(n);

    // Output the solutions
    for (const auto& board : solutions) {
        for (const auto& row : board) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
