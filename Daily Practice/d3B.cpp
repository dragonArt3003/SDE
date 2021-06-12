# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if (n == 1)
            return {0};
        
        vector<std::unordered_set<int>> adjList(n);
        
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[u].insert(v);
            adjList[v].insert(u);
        }
        
        queue<int> que;
        
        for (int i = 0; i < adjList.size(); i++)
            if (adjList[i].size() == 1)
                que.push(i);
        
        
        while (n > 2){
            int size = que.size();
            n = n - size;
            
            for (int i = 0; i < size; i++){
                int cur = que.front();
                que.pop();
                
                for (auto &adj: adjList[cur]){
                    adjList[adj].erase(cur);
                    if (adjList[adj].size() == 1)
                        que.push(adj);
                }
            }
        }
        
        while(que.empty() == false){
            ans.push_back(que.front());
            que.pop();
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> edges = {{3,0}, {3,1}, {3,2}, {3,4}, {5,4}};
    vector <int> ans = sol.findMinHeightTrees(6, edges);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
  
