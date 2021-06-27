class Solution {
public:
    bool rowCheck(vector<vector<char>> &A){
        int n = 9;
        for (int row = 0; row < n; row += 1){
            vector<bool> check(n, false);
            for (int col = 0; col < n; col += 1){
                char ch = A[row][col];
                if (ch == '.')
                    continue;
                if ('1' <= ch && ch <= '9' && check[ch - '1'] == true)
                    return false;
                check[ch - '1'] = true;
            }
        }
        return true;
    }
    
    bool colCheck(vector<vector<char>> &A){
        int n = 9;
        for (int col = 0; col < n; col += 1){
            vector<bool> check(n, false);
            for (int row = 0; row < n; row += 1){
                char ch = A[row][col];
                if (ch == '.')
                    continue;
                if ('1' <= ch && ch <= '9' && check[ch - '1'] == true)
                    return false;
                check[ch - '1'] = true;
            }
        }    
        return true;
    }
    
    bool cubeCheckUtil(vector<vector<char>> &A, int startR, int endR, int startC, int endC){
        vector<bool> check(9, false);
        for (int row = startR; row < endR; row += 1){
            for (int col = startC; col < endC; col += 1){
                char ch = A[row][col];
                if (ch == '.')
                    continue;
                if ('1' <= ch && ch <= '9' && check[ch - '1'] == true)
                    return false;
                check[ch - '1'] = true;
            }
        }
        return true;
    }
    
    bool cubeCheck(vector<vector<char>> &A){
        int n = 9;
        for (int row = 0; row < n; row += 3){
            for (int col = 0; col < n; col += 3){
                if (cubeCheckUtil(A, row, row + 3, col, col + 3) == false)
                    return false;
            }            
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& A) {
         // 
        return rowCheck(A) && colCheck(A) && cubeCheck(A);
    }
};
