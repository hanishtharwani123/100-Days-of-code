// 48. Symmetric Tree
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        
        return isSymmetricHelper(root->left, root->right);
    }
    
    bool isSymmetricHelper(TreeNode* leftSubtree, TreeNode* rightSubtree) {
        if (!leftSubtree && !rightSubtree)
            return true;
        
        if (!leftSubtree || !rightSubtree)
            return false;
        
        return (leftSubtree->val == rightSubtree->val) &&
               isSymmetricHelper(leftSubtree->left, rightSubtree->right) &&
               isSymmetricHelper(leftSubtree->right, rightSubtree->left);
    }
};

int main() {
    // Construct the example tree [1,2,2,3,4,4,3]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution solution;
    bool isSymmetric = solution.isSymmetric(root);

    if (isSymmetric)
        std::cout << "The tree is symmetric." << std::endl;
    else
        std::cout << "The tree is not symmetric." << std::endl;

    // Clean up memory (delete the tree nodes)
    // You can write a separate function to handle this recursively

    return 0;
}
