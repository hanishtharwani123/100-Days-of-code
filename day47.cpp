// 47. Validate Binary Search Tree
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
    
private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (node == nullptr) {
            return true;
        }
        
        if ((minNode != nullptr && node->val <= minNode->val) ||
            (maxNode != nullptr && node->val >= maxNode->val)) {
            return false;
        }
        
        return isValidBSTHelper(node->left, minNode, node) &&
               isValidBSTHelper(node->right, node, maxNode);
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    
    Solution solution;
    bool isValid = solution.isValidBST(root);
    
    if (isValid) {
        std::cout << "The given binary tree is a valid BST." << std::endl;
    } else {
        std::cout << "The given binary tree is not a valid BST." << std::endl;
    }
    
    // Clean up the allocated memory (you can implement a proper destructor)
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}
