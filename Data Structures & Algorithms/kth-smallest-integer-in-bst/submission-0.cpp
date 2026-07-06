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
    int kthSmallest(TreeNode* root, int k) {
        int res;
        int index = 0;
        recurse(root, index, k, res);

        return res;
    }

    void recurse(TreeNode* root, int& index, int const& k, int& res) {
        if (index == k) {
            return;
        }
        if (root->left) {
            recurse(root->left, index, k, res);
        }
        index++;
        if (index == k) {
            res = root->val;
            return;
        }
        if (root->right) {
            recurse(root->right, index, k, res);
        }
    }
};
