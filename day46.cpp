// 46. Binary Tree Inorder Traversal
#include <iostream>
#include <vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == NULL) {
            return;
        }

        inorderHelper(node->left, result);  // Traverse left subtree
        result.push_back(node->val);       // Process current node
        inorderHelper(node->right, result); // Traverse right subtree
    }
};

int main() {
    // Constructing the example binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> inorderResult = solution.inorderTraversal(root);

    // Printing the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory (optional, but recommended)
    // You can implement a separate function to delete the tree nodes.

    return 0;
}
