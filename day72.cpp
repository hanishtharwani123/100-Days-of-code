// 72. Binary Tree Right Side View
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }

        queue<TreeNode*> levelQueue;
        levelQueue.push(root);

        while (!levelQueue.empty()) {
            int levelSize = levelQueue.size();
            TreeNode* lastNode = nullptr;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = levelQueue.front();
                levelQueue.pop();

                // Update the last node at this level
                lastNode = current;

                if (current->left) {
                    levelQueue.push(current->left);
                }
                if (current->right) {
                    levelQueue.push(current->right);
                }
            }

            // Add the value of the last node to the result
            result.push_back(lastNode->val);
        }

        return result;
    }
};

int main() {
    // Create a binary tree as an example
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    // Create a Solution object
    Solution solution;

    // Get the right side view of the binary tree
    vector<int> rightView = solution.rightSideView(root);

    // Print the result
    cout << "Right Side View: ";
    for (int val : rightView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
