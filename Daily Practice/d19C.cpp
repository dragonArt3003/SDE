class Solution {
public:
    int rowCount, colCount;
    
    bool isInside(int r, int c){
        if (0 <= r && r < rowCount)
            if (0 <= c && c < colCount)
                return true;
        return false;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        rowCount = A.size(), colCount = A[0].size();
        vector<vector<int>> dist(rowCount, vector<int>(colCount, 0));
        dist[0][0] = 1;
        for (int i = 0; i < rowCount; i++){
            for (int j = 0; j < colCount; j++){
                if (A[i][j] == 1)   dist[i][j] = 0;
                else {
                    dist[i][j] += isInside(i, j - 1) ? dist[i][j - 1] : 0;
                    dist[i][j] += isInside(i - 1, j) ? dist[i - 1][j] : 0;
                }
            }
        }
        return dist[rowCount - 1][colCount - 1];
    }
};
