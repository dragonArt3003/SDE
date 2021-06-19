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
    void pathSumUtil(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp, int curSum, int targetSum){
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr){
            if (curSum + root->val == targetSum){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
            else
                return;
        }
        temp.push_back(root->val);
        
        pathSumUtil(root->left, ans, temp, curSum + root->val, targetSum);
        pathSumUtil(root->right, ans, temp, curSum + root->val, targetSum);
        
        temp.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        pathSumUtil(root, ans, temp, 0, targetSum);
        return ans;
    }
};
