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
    int maxProduct(TreeNode* root) {
        sum = treeSum(root);

        treeSum(root);

        return bestProduct % (int)(1e9 + 7);
    }

    int treeSum(TreeNode* node) {
        if (!node) {
            return 0;
        }

        runningSum = node->val + treeSum(node->left) + treeSum(node->right); 

        bestProduct = max(bestProduct, runningSum * (sum - runningSum));

        return runningSum;
    }
private:
    long long sum = 0, runningSum = 0, bestProduct = 0;
};
