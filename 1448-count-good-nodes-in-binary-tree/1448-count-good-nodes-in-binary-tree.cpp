/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
    int dfs(TreeNode* node, int maxi) {
        if (!node) {
            return 0;
        }
        int cnt = 0;
        if (node->val >= maxi) {
            cnt = 1;
        }
        maxi = max(maxi, node->val);
        cnt += dfs(node->left, maxi);
        cnt += dfs(node->right, maxi);
        return cnt;
    }
};