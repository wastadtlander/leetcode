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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        TreeNode* ans = new TreeNode();
        merge(ans, root1, root2);
        return ans;
    }

    void merge(TreeNode* ans, TreeNode* r1, TreeNode* r2) {
        if (!r1 && !r2) return;
        if (r1) ans->val += r1->val;
        if (r2) ans->val += r2->val;
        if (r1 && r1->left || r2 && r2->left) {
            ans->left = new TreeNode();
            merge(ans->left, r1 && r1->left ? r1->left : nullptr, r2 && r2->left ? r2->left : nullptr);
        }
        if (r1 && r1->right || r2 && r2->right) {
            ans->right = new TreeNode();
            merge(ans->right, r1 && r1->right ? r1->right : nullptr, r2 && r2->right ? r2->right : nullptr);
        }
    }
};
