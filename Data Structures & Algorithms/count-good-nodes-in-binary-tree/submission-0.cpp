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
    int goodNodes(TreeNode* root) {
        int res = 0;
        recurse(res, root->val, root);

        return res;
    }

    void recurse(int& res, int currMax, TreeNode* root) {
        if (!root) {
            return;
        }
        if (root->val >= currMax) {
            cout << root->val;
            res++;
            recurse(res, root->val, root->left);
            recurse(res, root->val, root->right);
        } else {
            recurse(res, currMax, root->left);
            recurse(res, currMax, root->right);
        }
    }
};
