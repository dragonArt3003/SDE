# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        
        vector<vector<int>> allTemp;
        for (int i = 0; i < m; i++){
            int r, c;
            r = i, c = 0;
            vector<int> temp;
            while (r >= 0 && c < n){
                temp.push_back(mat[r][c]);
                r--, c++;
            }
            allTemp.push_back(temp);
        }
        
        for (int i = 1; i < n; i++){
            int r, c;
            r = m - 1, c = i;
            vector<int> temp;
            while (r >= 0 && c < n){
                temp.push_back(mat[r][c]);
                r--, c++;
            }
            allTemp.push_back(temp);
        }
        
        for (int i = 0; i < allTemp.size(); i++){
            if (i % 2 == 0){
                for (int j = 0; j < allTemp[i].size(); j++)
                    res.push_back(allTemp[i][j]);
            }
            else{
                for (int j = allTemp[i].size() - 1; j >= 0; j--)
                    res.push_back(allTemp[i][j]);
            }
        }
        
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    Solution sol;
    for (int i = 0; i < n; i++)
         cin >> A[i];
    vector<int> B = sol.findDiagonalOrder(A);
    for (int i = 0; i < B.size(); i++)
        cout << B[i] << " ";
    cout << endl;
    return 0;
}
