#include <bits/stdc++.h>
using namespace std;

/*
creates the adjacency list for undirected graphs.
*/
vector<vector<int>> buildAdjList(int V, vector<pair<int, int>> &edges) {
    vector<vector<int>> adjList(V);

    for(int i = 0; i < edges.size(); i++) {
        int u, v;
        u = edges[i].first;
        v = edges[i].second;
        if (adjList[u].size() == 0) 
            adjList[u] = vector<int>();
        adjList[u].push_back(v);
    }
    return adjList;
}

/*
print adj list.
*/
void printAdjList(vector<vector<int>> &adjList) {
    int cur = 0;
    for (auto edges: adjList) {
        std::cout << cur ;
        for (auto node: edges) {
            std::cout << " -> " << node;
        }
        std::cout << std::endl;
        cur += 1;
    }
}

int main() {
    vector<vector<int>> adjList;
    int V, E;
    vector<pair<int, int>> edges;
    std::cin >> V >> E;

    for(int i = 0; i < E; i++) {
        pair<int, int> temp;
        std::cin >> temp.first >> temp.second;
        edges.push_back(temp);
    }

    adjList = buildAdjList(V, edges);

    printAdjList(adjList);
}
