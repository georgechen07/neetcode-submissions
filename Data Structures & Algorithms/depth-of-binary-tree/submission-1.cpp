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
    int maxDepth(TreeNode* root) {
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root, 1});
        int res = 0;
        while (!nodes.empty()) {
            auto [node, depth] = nodes.top();
            nodes.pop();
            if (node == nullptr) {
                continue;
            }
            res = max(res, depth);
            nodes.push({node->left, depth + 1});
            nodes.push({node->right, depth + 1});
        }

        return res;
    }
};
