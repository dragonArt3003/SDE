class Solution {
public:
    int N, K;
    
    void solve(vector<vector<int>> &res, vector<int> &temp, int beg, int rem){
        if (rem == 0){
            res.push_back(temp);
            return;
        }
        
        for (int i = beg; i <= N; i += 1){
            temp.push_back(i);
            solve(res, temp, i + 1, rem - 1);
            temp.pop_back();            
        }
    }
    
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        N = n, K = k;
        solve(res, temp, 1, K);
        return res;
    }
};
