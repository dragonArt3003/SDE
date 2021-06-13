class NumArray {
public:
    struct TreeNode{
        int sum;
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    };
    
    TreeNode* buildTree(vector<int> &A, int start, int end){
        if (start > end)
            return nullptr;
        TreeNode *temp = new TreeNode();
        
        if (start == end){
            temp->sum = A[start];
            return temp;
        }    
        int mid = start + (end - start) / 2;
        temp->left = buildTree(A, start, mid);
        temp->right = buildTree(A, mid + 1, end);
        temp->sum = temp->left->sum + temp->right->sum;
        return temp;
    }
    
    TreeNode *root = nullptr;
    int n;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        root = buildTree(nums, 0, nums.size() - 1); 
    }
    
    void inOrder(TreeNode *root){
        if (root == nullptr)    return;
        inOrder(root->left);
        cout << root->sum << " ";
        inOrder(root->right);
    }
    
    void printInorder(TreeNode *root){
        inOrder(root);
        cout << endl;
    }
    
    void updateUtil(TreeNode *root, int index, int val, int start, int end){
        if (start == index && index == end){
            root->sum = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (index <= mid)
            updateUtil(root->left, index, val, start, mid);
        else
            updateUtil(root->right, index, val, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
    }
    
    void update(int index, int val) {
        // cout << "Before : ";
        // printInorder(root);
        updateUtil(root, index, val, 0, n - 1);
        // cout << "After : ";
        // printInorder(root);
    }
    
    int sumRangeUtil(TreeNode *root, int start, int end, int left, int right){
        // Total overlap:
        if (left <= start && end <= right)
            return root->sum;
    
        // No overlap:
        if (end < left || right < start)
            return 0;
    
        // Partial Overlap:
        // if ((start <= left && left <= end) || (start <= right && right <= end) || (start <= left && right <= end)){
        int mid = start + (end - start) / 2;
        return sumRangeUtil(root->left, start, mid, left, right) + sumRangeUtil(root->right, mid + 1, end, left, right);
        
    }
    
    int sumRange(int left, int right) {
        return sumRangeUtil(root, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
