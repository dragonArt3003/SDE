#include <bits/stdc++.h>

std::vector<std::vector<std::pair<int, int>>> makeAdjList(int V, std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<std::pair<int, int>>> adjList(V);
    
    for(auto edge: edges) {
        int u, v, w;
        u = edge[0], v = edge[1], w = edge[2];          // (src, dest, weight)
        adjList[u].push_back(std::make_pair(v, w)); 
    }

    return adjList;
}

void makePath(std::vector<int> &parent, int cur) {
    if (parent[cur] == -1){
        std::cout << cur ;
        return;
    }
    makePath(parent, parent[cur]);
    std::cout << " -> " << cur;
}

void dijkstras(int V, int E, std::vector<std::vector<int>> &edges, int src) {
    std::vector<std::vector<std::pair<int, int>>> adjList = std::move(makeAdjList(V, edges));
    std::vector<bool> isCompleted(V, false);
    std::vector<int> parent(V, -1);
    std::vector<int> dist(V, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> que;

    // max heap: <dist, node id> 

    que.push(std::make_pair(0, src));
    dist[src] = 0;


    while(!que.empty()) {
        auto cur = que.top();
        que.pop();

        int u = cur.second;
        isCompleted[u] = true;

        for(auto adj: adjList[u]) {
            int v = adj.first;
            int w = adj.second;

            if (isCompleted[v] == false && dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                que.push(std::make_pair(dist[v], v));
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (i == src) 
            continue;
        makePath(parent, i);
        std::cout << " | cost : " << dist[i] << std::endl;
    }
}

int main() {
    int V, E;
    std::vector<std::vector<int>> edges;
    std::cin >> V >> E;
    for (int i = 0; i < E; i++) {
        std::vector<int> edge(3);
        std::cin >> edge[0] >> edge[1] >> edge[2];
        edges.push_back(edge);
    }

    dijkstras(V, E, edges, 0);

    return 0;
}