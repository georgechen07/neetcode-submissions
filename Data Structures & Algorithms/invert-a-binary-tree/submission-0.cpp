/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            TreeNode* curr = nodes.top();
            nodes.pop();
            if (curr == nullptr) {
                continue;
            }
            TreeNode* temp = std::move(curr->right);
            curr->right = std::move(curr->left);
            curr->left = std::move(temp);
            nodes.push(curr->left);
            nodes.push(curr->right);
        }

        return root;
    }
};
