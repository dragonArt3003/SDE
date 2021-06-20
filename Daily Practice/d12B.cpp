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
    std::unordered_map<string, int> ht;
    vector<TreeNode*> res;
    
    string solve(TreeNode *root){
        if (root == nullptr)    return "#";
        
        string left = solve(root->left);
        string right = solve(root->right);
        
        string cur = to_string(root->val) + "|" + left + "|" + right;
        
        ht[cur] += 1;
        if (ht.find(cur) != ht.end() && ht[cur] == 2)
            res.push_back(root);
        return cur;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return res;
    }
};
