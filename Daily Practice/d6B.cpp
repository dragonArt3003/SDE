class Solution {
public:
    void makeAdjList(vector<vector<int>> &edges, vector<vector<int>> &adjList){
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adjList[v].push_back(u);            
        }
    }
    
    bool isCyclic(vector<vector<int>> &adjList, vector<bool> &inStack, vector<bool> &visited, int cur){
        inStack[cur] = true;
        visited[cur] = true;
        
        for (int i = 0; i < adjList[cur].size(); i++){
            int adj = adjList[cur][i];
            if (visited[adj] == true && inStack[adj] == true)
                return true;
            if (visited[adj] == false)
                if (isCyclic(adjList, inStack, visited, adj))
                    return true;
        }
        inStack[cur] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        makeAdjList(prerequisites, adjList);
        vector<bool> inStack(numCourses, false);
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < numCourses; i++){
            if (isCyclic(adjList, inStack, visited, i))
                return false;
        }
        return true;
    }
};
