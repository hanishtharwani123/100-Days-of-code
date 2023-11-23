// 99. Rotting Oranges
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        std::queue<std::pair<int, int>> rottenQueue;

        // Add all initial rotten oranges to the queue
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }

        // Define 4-directional neighbors
        int directions[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Perform BFS to spread rotting
        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();

            for (int i = 0; i < size; ++i) {
                int x = rottenQueue.front().first;
                int y = rottenQueue.front().second;
                rottenQueue.pop();

                for (auto& dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                        grid[newX][newY] = 2;  // Mark the fresh orange as rotten
                        rottenQueue.push({newX, newY});
                    }
                }
            }

            if (!rottenQueue.empty()) {
                minutes++;
            }
        }

        // Check if there are any remaining fresh oranges
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return -1;  // There are remaining fresh oranges
                }
            }
        }

        return minutes;
    }
};

int main() {
    // Example usage
    Solution solution;
    std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int result = solution.orangesRotting(grid);

    // Output the result
    std::cout << "Minutes to rot all oranges: " << result << std::endl;

    return 0;
}
