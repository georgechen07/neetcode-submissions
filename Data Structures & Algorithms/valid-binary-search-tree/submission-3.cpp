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
    bool isValidBST(TreeNode* root) {
        int res = 0;
        queue<tuple<TreeNode*, int, int>> q;
        if (root->left) {
            q.push({root->left, INT_MIN, root->val});
        }
        if (root->right) {
            q.push({root->right, root->val, INT_MAX});
        }

        while (!q.empty()) {
            auto [node, min, max] = q.front();
            q.pop();
            if (node->val >= max || node->val <= min) {
                return false;
            }
            if (node->left) {
                q.push({node->left, min, node->val});
            }
            if (node->right) {
                q.push({node->right, node->val, max});
            }
        }

        return true;
    }
};
