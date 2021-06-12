# include <bits/stdc++.h>
using namespace std;

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
    std::unordered_map<int, int> ht;
    int preInd;
    
    TreeNode* construct(vector<int> &pre, vector<int> &post, int postStart, int postEnd){
        if (postStart > postEnd)
            return nullptr;
        TreeNode *temp = new TreeNode(pre[preInd]);
        preInd++;
        if (postStart == postEnd)
            return temp;
        int postInd = ht[pre[preInd]];
        temp->left = construct(pre, post, postStart, postInd);
        temp->right = construct(pre, post, postInd + 1, postEnd - 1);
        return temp;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        for (int i = 0; i < post.size(); i++)
            ht.insert({post[i], i});
        
        return construct(pre, post, 0, post.size() - 1);
    }
};

void printInOrder(TreeNode *root){
    if (root == nullptr)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int mani(){
    int n;
    cin >> n;
    vector<int> pre(n), post(n);
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    
    for (int j = 0; j < n; j++)
        cin >> post[i];
       
    Solution sol;
    TreeNode *root = sol.constructFromPrePost(pre, post);
    return 0;
}
