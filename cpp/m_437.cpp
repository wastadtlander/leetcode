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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int count = findValidPaths(root, targetSum, 0);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }

    int findValidPaths(TreeNode* root, int targetSum, long long runningSum) {
        if (!root) return 0;
        runningSum += root->val;
        int count = (runningSum == targetSum) ? 1 : 0;
        count += findValidPaths(root->left, targetSum, runningSum);
        count += findValidPaths(root->right, targetSum, runningSum);
        return count;
    }
};
