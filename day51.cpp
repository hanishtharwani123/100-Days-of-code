// 51. Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }
        
        int rootValue = preorder[preStart];
        int rootIndex = inStart;
        while (rootIndex <= inEnd && inorder[rootIndex] != rootValue) {
            rootIndex++;
        }
        
        int leftSubtreeSize = rootIndex - inStart;
        
        TreeNode* root = new TreeNode(rootValue);
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSubtreeSize, inorder, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + leftSubtreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd);
        
        return root;
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    TreeNode* root = solution.buildTree(preorder, inorder);

    return 0;
}
