// 53.  Pascal's Triangle
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows == 0)
            return result;

        result.push_back({1});  // First row
        
        for (int i = 1; i < numRows; ++i) {
            vector<int> row(i + 1, 1);  // Initialize the row with 1s
            
            for (int j = 1; j < i; ++j) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];  // Calculate values based on the row above
            }
            
            result.push_back(row);
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    int numRows = 5;
    vector<vector<int>> pascalsTriangle = solution.generate(numRows);
    
    // Printing the generated Pascal's triangle
    for (const vector<int>& row : pascalsTriangle) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
