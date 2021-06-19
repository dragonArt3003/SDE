class Solution {
public:
    std::unordered_map<string, int> dp;
    int rowCount, colCount;
    long MOD = std::pow(10, 9) + 7;
    
    bool isInside(int r, int c){
        if (0 <= r && r < rowCount)
            if (0 <= c && c < colCount)
                return true;
        return false;
    }
    
    
    int constructDP(int r, int c, int moveRem){
        string key = to_string(r) + "#" + to_string(c) + "#" + to_string(moveRem);
        if (dp.find(key) != dp.end())
            return dp[key];
        if (r < 0 || c < 0 || r >= rowCount || c >= colCount)
            return 1;
        if (moveRem <= 0)
            return 0;
        int moveCount = 0;
        vector<pair<int, int>> proxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < proxy.size(); i++){
            int adjRow = r + proxy[i].first;
            int adjCol = c + proxy[i].second;
            moveCount = (moveCount + constructDP(adjRow, adjCol, moveRem - 1)) % MOD;
        }
        dp[key] = moveCount;
        return dp[key];
    }

    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rowCount = m;
        colCount = n;
        return constructDP(startRow, startColumn, maxMove);
    }
};
