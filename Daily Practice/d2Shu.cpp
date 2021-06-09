# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInside(int r, int c, int maxR, int maxC){
        if (0 <= r && r <= maxR)
            if (0 <= c && c <= maxC)
                return true;
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size(); 
        vector<vector<bool>> inQue(m, vector<bool>(n, false));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<pair<int, int>> proxy = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        std::queue<pair<int, int>> que;
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (mat[i][j] == 0)
                    que.push({i, j});
            }
        }
        
        while (que.empty() == false){
            pair<int, int> cur = que.front();
            que.pop();
            int r = cur.first, c = cur.second;
            inQue[r][c] = true;
            
            for (int i = 0; i < proxy.size(); i++){
                int adjR = r + proxy[i].first;
                int adjC = c + proxy[i].second;
                
                if (isInside(adjR, adjC, m - 1, n - 1) && mat[adjR][adjC] == 1 && inQue[adjR][adjC] == false){
                    dist[adjR][adjC] = dist[r][c] + 1;
                    que.push({adjR, adjC});
                    inQue[adjR][adjC] = true;
                }
            }
        }
        return dist;
    }
};

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    Solution sol;
    vector<vector<int>> ans = sol.updateMatrix(mat);
    
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
             cout << mat[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
    
