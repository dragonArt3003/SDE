#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isInside(int r, int c, int maxR, int maxC){
        if (0 <= r && r <= maxR)
            if (0 <= c && c <= maxC)
                return true;
        return false;
    }
 
    void dfs(vector<vector<char>> &mat, vector<vector<bool>> &convert, vector<vector<bool>> &visited, int r, int c){
        int maxR = mat.size() - 1;
        int maxC = mat[0].size() - 1;
 
        visited[r][c] = true;
        convert[r][c] = false;
 
        vector<pair<int, int>> proxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
 
        for (int i = 0; i < proxy.size(); i++){
            int adjR = r + proxy[i].first;
            int adjC = c + proxy[i].second;
            if (isInside(adjR, adjC, maxR, maxC) && mat[adjR][adjC] == 'O' && visited[adjR][adjC] == false)
                dfs(mat, convert, visited, adjR, adjC);
        }
    }
 
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<bool>> convert(n, vector<bool>(m, true));
 
        for (int i = 0; i < m; i++)
            if (visited[0][i] == false && mat[0][i] == 'O')
                dfs(mat, convert, visited, 0, i);
 
        for (int i = 0; i < n; i++)
            if (visited[i][m - 1] == false && mat[i][m - 1] == 'O')
                dfs(mat, convert, visited, i, m - 1);
 
        for (int i = m - 1; i >= 0; i--)
            if (visited[n - 1][i] == false && mat[n - 1][i] == 'O')
                dfs(mat, convert, visited, n - 1, i);
 
        for (int i = n - 1; i >= 0; i--)
            if (visited[i][0] == false && mat[i][0] == 'O')
                dfs(mat, convert, visited, i, 0);
 
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (convert[i][j] == true)
                    mat[i][j] = 'X';
                else
                    mat[i][j] = 'O';
 
        return mat;
    }
};
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
 
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
