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
    bool pruneCurNode(TreeNode *root){
        if (root == nullptr)
            return true;
        bool left = pruneCurNode(root->left);
        bool right = pruneCurNode(root->right);
        root->left = (left == true) ? nullptr : root->left;
        root->right = (right == true) ? nullptr : root->right;
        if (root->val != 1){
            if (left == true && right == true){
                // delete root;
                return true;
            }
        }
        return false;
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        if (pruneCurNode(root))
            return nullptr;
        return root;
    }
};
