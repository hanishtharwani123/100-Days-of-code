// 55. Binary Tree Maximum Path Sum
#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize with a very small value
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }

private:
    int maxPathSumHelper(TreeNode* node, int& maxSum) {
        if (node == nullptr) {
            return 0;
        }
        
        // Calculate the maximum path sum for left and right subtrees
        int leftMax = maxPathSumHelper(node->left, maxSum);
        int rightMax = maxPathSumHelper(node->right, maxSum);
        
        // Calculate the maximum path sum for the current node
        int currentMax = std::max(node->val, node->val + std::max(leftMax, rightMax));
        
        // Calculate the maximum path sum that goes through the current node and continues down to its subtrees
        int maxThroughCurrent = std::max(currentMax, node->val + leftMax + rightMax);
        
        // Update the global maximum path sum
        maxSum = std::max(maxSum, maxThroughCurrent);
        
        // Return the maximum path sum that starts at the current node and goes up towards its parent node
        return currentMax;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    std::cout << "Maximum Path Sum: " << solution.maxPathSum(root) << std::endl;

    return 0;
}
