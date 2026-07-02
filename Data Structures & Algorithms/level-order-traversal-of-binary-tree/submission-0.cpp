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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        vector<vector<int>> res;
        res.push_back({root->val});
        recurse(root->left, res, 1);
        recurse(root->right, res, 1);

        return res;
    }

    void recurse(TreeNode* root, vector<vector<int>>& res, int level) {
        if (root == NULL) {
            return;
        }
        
        if (res.size() > level) {
            res[level].push_back(root->val);
        } else {
            res.push_back({root->val});
        }

        recurse(root->left, res, level + 1);
        recurse(root->right, res, level + 1);
    }
};
