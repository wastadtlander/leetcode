/*
 * To my understanding this problem is solved by doing a postorder traversal where you keep track of the largest path sum from a given node 
 * i through all of it's children. Since you are working bottom up we will always be keeping track of the largest path sum and therfore can
 * easily add onto or replace it.
 */
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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        postorderSum(root, maxSum);
        return maxSum;
    }

    int postorderSum(TreeNode* node, int& maxSum) {
        if (!node) {
            return 0;
        }

        int left = postorderSum(node->left, maxSum);
        int right = postorderSum(node->right, maxSum);
        int tempSum = max(max(left, right) + node->val, node->val);
        maxSum = max(maxSum, max(tempSum, left + right + node->val));
        return tempSum;
    }
};
