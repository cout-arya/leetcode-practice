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
    void dfs(TreeNode* node, int sum, int targetSum, vector<vector<int>>& res,
             vector<int>& path) {
        if (!node)
            return;
        sum += node->val;
        path.push_back(node->val);
        if (!node->left && !node->right && sum == targetSum) {
            vector<int> arr;
            for (int i = 0; i < path.size(); i++) {
                arr.push_back(path[i]);
            }
            res.push_back(arr);
        } else {

            dfs(node->left, sum, targetSum, res, path);
            dfs(node->right, sum, targetSum, res, path);
        }
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, 0, targetSum, res, path);
        return res;
    }
};