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
    void dfs(TreeNode* node, vector<string>& res, vector<int>& path) {
        if (!node)
            return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string pathStr;
            for (int i = 0; i < path.size(); i++) {
                pathStr += to_string(path[i]);
                if (i < path.size() - 1) {
                    pathStr += "->";
                }
            }
            res.push_back(pathStr);
        } else {
            dfs(node->left, res, path);
            dfs(node->right, res, path);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        dfs(root, res, path);
        return res;
    }
};