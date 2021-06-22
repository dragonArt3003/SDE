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
    
    void getInorder(TreeNode *root, vector<int> &inOrder){
        if (root == nullptr)    return;
        getInorder(root->left, inOrder);
        inOrder.push_back(root->val);
        getInorder(root->right, inOrder);
    }
    
    TreeNode* buildTree(vector<int> &inOrder, int l, int r){
        if (l > r)  return nullptr;
        if (l == r) return new TreeNode(inOrder[l]);
        int mid = l + (r - l) / 2;
        TreeNode *cur = new TreeNode(inOrder[mid]);
        cur->left = buildTree(inOrder, l, mid - 1);
        cur->right = buildTree(inOrder, mid + 1, r);
        return cur;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        
        getInorder(root, inOrder);
        
        return buildTree(inOrder, 0, inOrder.size() - 1);
    }
};
