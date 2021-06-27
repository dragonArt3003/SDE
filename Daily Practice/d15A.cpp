class Solution {
public:
    int n;
    
    bool isInside(int r, int c){
        if (0 <= r && r < n)
            if (0 <= c && c < n)
                return true;
        return false;
    }
    
    int minFallingPathSum(vector<vector<int>>& A) {
        n = A.size();
        if (n == 1)
            return A[0][0];
        int ans = INT_MAX;
        vector<vector<int>> sum(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++)
            sum[0][i] = A[0][i];
        
        
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n; j++){
                int a = isInside(i - 1, j - 1) ? sum[i - 1][j - 1] : INT_MAX;
                int b = isInside(i - 1, j) ? sum[i - 1][j] : INT_MAX;
                int c = isInside(i - 1, j + 1) ? sum[i - 1][j + 1] : INT_MAX;
                
                sum[i][j] = A[i][j] + std::min(a, std::min(b, c));
                
                if (i == n - 1)
                    ans = std::min(ans, sum[i][j]);
            }
        }
        
        return ans;
    }
};
