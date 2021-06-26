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
    int maxLen = 0;
    
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr)    return 0;
        int l = solve(root->left, root->val);
        int r = solve(root->right, root->val);
        maxLen = std::max(maxLen, l + r + 1);
        return maxLen - 1;
    }
    
    int solve(TreeNode *root, int parVal){
        if (!root)  return 0;
        
        int l = solve(root->left, root->val);
        int r = solve(root->right, root->val);
        
        maxLen = std::max(maxLen, l + r + 1);
        
        if (root->val == parVal)
            return 1 + std::max(l, r);
        return 0;
    }
};
