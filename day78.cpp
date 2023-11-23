// 78.  Invert Binary Tree
#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if the root is null, return null
        if (root == nullptr) {
            return nullptr;
        }

        // Swap the left and right subtrees
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }
};

// Utility function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (root != nullptr) {
        printTree(root->left);
        std::cout << root->val << " ";
        printTree(root->right);
    }
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    // Print the inverted tree
    std::cout << "Inverted Tree: ";
    printTree(invertedRoot);

    return 0;
}
