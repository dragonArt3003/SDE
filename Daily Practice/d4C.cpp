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
    int maxEleInd(vector<int> &A, int l, int r){
        int max, maxInd;
        max = INT_MIN;
        for (int i = l; i <= r; i++){
            if (A[i] > max){
                max = A[i];
                maxInd = i;
            }
        }
        return maxInd;
    }
    
    TreeNode* buildTree(vector<int> &A, int l, int r){
        // cout << l << ", " << r << endl;
        if (l > r) return nullptr;
        TreeNode *temp = new TreeNode();
        if (l == r){
            temp->val = A[l];
            temp->left = temp->right = nullptr;
            return temp;
        }
        int maxInd = maxEleInd(A, l, r);
        temp->val = A[maxInd];
        temp->left = buildTree(A, l, maxInd - 1);
        temp->right = buildTree(A, maxInd + 1, r);
        return temp;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
