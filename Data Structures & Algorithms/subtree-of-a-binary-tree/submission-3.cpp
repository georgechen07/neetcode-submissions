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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> dfs;
        dfs.push(root);
        while (!dfs.empty()) {
            auto top = dfs.top();
            dfs.pop();
            if (recurseTree(top, subRoot)) {
                return true;
            }
            if (top->left != nullptr) {
                dfs.push(top->left);
            }
            if (top->right != nullptr) {
                dfs.push(top->right);
            }
        }

        return false;
    }

    bool recurseTree(TreeNode* root, TreeNode* subRoot) {
        if ((root == nullptr && subRoot == nullptr)) {
            return true;
        } else if ((root == nullptr && subRoot != nullptr) || (root != nullptr && subRoot == nullptr)) {
            return false;
        } else if (root->val != subRoot->val) {
            return false;
        }

        return recurseTree(root->left, subRoot->left) && recurseTree(root->right, subRoot->right);
    }
};
