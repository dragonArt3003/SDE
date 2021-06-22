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
    bool isCompleteTree(TreeNode* root) {
        bool last = false;
        
        std::queue<TreeNode*> que;
        que.push(root);
        
        while (!que.empty()){
            TreeNode *cur = que.front();
            que.pop();
            
            if (cur == nullptr)
                last = true;
            else{
                if (last == true)   return false;
                que.push(cur->left);
                que.push(cur->right);
            }
        }
        return true;
    }
};
