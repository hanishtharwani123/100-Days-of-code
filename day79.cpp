// 79. Kth Smallest Element in a BST
#include <iostream>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> nodes;
        TreeNode* current = root;

        while (current != nullptr || !nodes.empty()) {
            while (current != nullptr) {
                nodes.push(current);
                current = current->left;
            }

            current = nodes.top();
            nodes.pop();

            // Check if this is the kth smallest element
            if (--k == 0) {
                return current->val;
            }

            current = current->right;
        }

        // This should not be reached if the input is valid
        return -1;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    Solution solution;
    int result = solution.kthSmallest(root, 1);

    std::cout << "Kth smallest element: " << result << std::endl;

    return 0;
}
