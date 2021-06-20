class NumMatrix {
public:
    int rowCount, colCount;
    vector<vector<int>> A;
    
    bool isInside(int r, int c){
        if (0 <= r && r < rowCount)
            if (0 <= c && c < colCount)
                return true;
        return false;
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        rowCount = matrix.size();
        colCount = matrix[0].size();
        for (int i = 0; i < rowCount; i++)
            for (int j = 1; j < colCount; j++)
                matrix[i][j] += matrix[i][j - 1];
    
        for (int i = 1; i < rowCount; i++)
            for (int j = 0; j < colCount; j++)
                matrix[i][j] += matrix[i - 1][j];
        A = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        int a, b, c, d;
        a = (isInside(row1 - 1, col1 - 1) ? A[row1 - 1][col1 - 1] : 0);
        b = (isInside(row1 - 1, col2) ? A[row1 - 1][col2] : 0);
        c = (isInside(row2, col1 - 1) ? A[row2][col1 - 1] : 0);
        d = A[row2][col2];
        return d + a - b - c;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
