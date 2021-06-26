class Solution {
public:
    int solve(vector<vector<int>> &dp, int row, int col){
        if(row < 0 || col < 0) 
            return 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        if(row == 0 && col == 0)
            return dp[row][col] = 1;
        dp[row][col] = solve(dp, row - 1, col) + solve(dp, row, col - 1);
        return dp[row][col];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m);
        for(int i = 0; i < m; i++)
            dp[i] = vector<int>(n, -1);
    
        int ans = solve(dp, m - 1, n - 1);
        return ans;
    }
};
