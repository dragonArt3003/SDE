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
    bool hasPathSumUtil(TreeNode *root, int curSum, int targetSum){
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr)
            return ((curSum + root->val) == targetSum) ? true : false;
        if (hasPathSumUtil(root->left, curSum + root->val, targetSum))
            return true;
        return hasPathSumUtil(root->right, curSum + root->val, targetSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSumUtil(root, 0, targetSum);
    }
};
