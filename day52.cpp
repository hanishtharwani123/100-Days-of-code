// 52. Flatten Binary Tree to Linked List
#include <iostream>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        TreeNode* originalRight = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        TreeNode* rightmost = root;
        while (rightmost->right) {
            rightmost = rightmost->right;
        }
        
        rightmost->right = originalRight;
        
        flatten(root->right);
    }
};

// Helper function to print the flattened linked list
void printLinkedList(TreeNode* head) {
    while (head) {
        std::cout << head->val << " -> ";
        head = head->right;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    
    Solution solution;
    solution.flatten(root);
    
    // Print the flattened linked list
    printLinkedList(root);
    
    // Clean up memory (optional)
    // You can implement a function to delete the tree nodes to avoid memory leaks
    
    return 0;
}
