// 50. Maximum Depth of Binary Tree
#include <iostream>
#include <algorithm> // for std::max
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: If the root is null, the depth is 0.
        if (root == nullptr) {
            return 0;
        }

        // Recursive case: Calculate the maximum depth of the left and right subtrees.
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return the maximum depth of the current node by adding 1 to the maximum of the left and right depths.
        return 1 + max(leftDepth, rightDepth);
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    int depth = solution.maxDepth(root);
    cout << "Maximum Depth of Binary Tree: " << depth << endl;

    // Clean up the allocated memory (not necessary in LeetCode)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
