// 94. Diameter of Binary Tree
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        calculateDepth(root, diameter);
        return diameter;
    }

private:
    int calculateDepth(TreeNode* node, int& diameter) {
        if (node == nullptr) {
            return 0;
        }

        int leftDepth = calculateDepth(node->left, diameter);
        int rightDepth = calculateDepth(node->right, diameter);

        // Update the diameter if the current path is longer
        diameter = std::max(diameter, leftDepth + rightDepth);

        // Return the depth of the current subtree
        return 1 + std::max(leftDepth, rightDepth);
    }
};

int main() {
    // Example usage
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int result = solution.diameterOfBinaryTree(root);

    // Don't forget to free the allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
