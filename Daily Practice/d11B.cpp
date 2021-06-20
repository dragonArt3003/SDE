/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *res = nullptr;
    bool found = false;
    bool pFound = false, qFound = false;
    int pVal, qVal;
    
    
    bool solve(TreeNode *node){
        if (node == nullptr)    return false;
        bool own = (node->val == pVal || node->val == qVal) ? true : false;
        
        bool left = solve(node->left);
        if (found == true)
            return true;
        bool right = solve(node->right);
        
        // cout << node->val << ", " << left << ", " << right << endl;
        
        if (((left && right) || (left && own) || (right && own)) && (found == false)){
            res = node;
            return true;
        }
        if (own || left || right)
            return true;
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pVal = p->val;
        qVal = q->val;
        solve(root);
        return res;
    }
};
