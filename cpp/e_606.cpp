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
    string tree2str(TreeNode* root) {
        string ans = "";
        if (root) {
            ans += to_string(root->val);
            dfs(root, ans);
        }
        return ans;
    }

    void dfs(TreeNode* root, string& ans) {
        if (!root) return;
        if (root->left) {
            ans.push_back('(');
            ans += to_string(root->left->val);
            dfs(root->left, ans);
            ans.push_back(')');
        }
        if (root->right) {
            if (!root->left) {
                ans += "()";
            }
            ans.push_back('(');
            ans += to_string(root->right->val);
            dfs(root->right, ans);
            ans.push_back(')');
        }
    }
};
