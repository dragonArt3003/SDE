#include <bits/stdc++.h>

std::vector<std::vector<int>> build_adj_list_und(int &V, int &E, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> adj_list(V);
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    return adj_list;
}

std::vector<std::vector<int>> build_adj_list_dir(int &V, int &E, const std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> adj_list(V);
    for(auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        adj_list[u].push_back(v);
    }
    return adj_list;
}

// processing all bfs reachable nodes from src:-
void bfs(const std::vector<std::vector<int>> &adj_list, std::vector<bool> &in_que, std::vector<int> &res, int src) {
    std::queue<int> que;

    que.push(src);
    in_que[src] = true;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        res.push_back(u);

        for(auto v: adj_list[u]) {
            if (in_que[v] == false) {
                que.push(v);
                in_que[v] = true;
            }
        }
    }
}

void bfs(int &V, int &E, std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> adj_list = std::move(build_adj_list_dir(V, E, edges));
    std::vector<bool> in_que(V, false);
    std::queue<int> que;
    std::vector<int> res;

    for(int i = 0; i < V; i++) {
        if (in_que[i] == false) {
            bfs(adj_list, in_que, res, i);
        }
    }

    std::cout << "BFS traversal: ";
    for(auto u: res)
        std::cout << u << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    int V, E;
    std::vector<std::vector<int>> edges;
    std::cin >> V >> E;
    for(int i = 0; i < E; i++) {
        std::vector<int> temp(2);
        std::cin >> temp[0] >> temp[1];
        edges.push_back(temp);
    }

    bfs(V, E, edges);
}

// switch between directed and undirected graph:
// for directed graph: use "build_adj_list_dir"
// for undirected graph: use "build_adj_list_und"

// input:-
// 8 10
// 0 2
// 0 3
// 1 3
// 1 4
// 2 5
// 3 5
// 3 6
// 4 6
// 5 7
// 6 7
