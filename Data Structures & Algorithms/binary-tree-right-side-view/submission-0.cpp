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
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        vector<int> res;
        int level = 0;
        int maxLevel = 0;
        recurse(root, level, maxLevel, res);

        return res;
    }

    void recurse(TreeNode* root, int level, int& maxLevel, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        if (level >= maxLevel) {
            res.push_back(root->val);
            maxLevel++;
        }
        recurse(root->right, level + 1, maxLevel, res);
        recurse(root->left, level + 1, maxLevel, res);
    }
};
