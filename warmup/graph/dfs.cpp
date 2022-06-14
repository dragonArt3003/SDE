#include <bits/stdc++.h>

void print(std::vector<int> &A) {
    for(auto ele: A)
        std::cout << " -> " << ele;
    std::cout << std::endl;
}

void print(std::vector<std::vector<int>> &A) {
    for(int i = 0; i < A.size(); i++){
        std::cout << i;
        print(A[i]);
    }
    std::cout << std::endl;
}

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

void dfsUtil(std::vector<std::vector<int>> &adj_list, std::vector<bool> &visited, std::vector<int> &parent, std::vector<int> &index, std::vector<int> &res, int &src) {
    std::stack<int> st;

    visited[src] = true;
    st.push(src);

    while (!st.empty()) {
        int u = st.top();

        // poping condition: when all the adjacents are processed 
        // remove the current vertex from the stack and add int resultant vector

        if (index[u] == adj_list[u].size()) {
            res.push_back(u);
            st.pop();
        }
        else {
            int ind = (index[u])++;
            int v = adj_list[u][ind];
            if (visited[v] == false) {
                parent[v] = u;
                st.push(v);
                visited[v] = true;
            }
        }
    }  
}

// non recursive or iterative dfs traversal:
void dfs(int &V, int &E, std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> adj_list = build_adj_list_und(V, E, edges);
    std::vector<int> index(V, 0);
    std::vector<bool> visited(V, false);
    std::vector<int> res;
    std::vector<int> parent(V, -1);

    std::cout << "adj_list: " << std::endl;
    print(adj_list);

    for (int i = 0; i < V; i++){
        if (visited[i] == false) {
            dfsUtil(adj_list, visited, parent,  index, res, i);        
        }
    }

    std::cout << "parent vector: " << std::endl;
    for (int i = 0; i < parent.size(); i++) {
        std::cout << "(" << i << ", " << parent[i] << ") | ";
    }
    std::cout << std::endl;

    std::reverse(res.begin(), res.end());

    std::cout << "dfs traversal array: " << std::endl;
    for(auto u: res) 
        std::cout << u << ", ";  
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

    int src = 0;
    dfs(V, E, edges);
}

// TODO: need to do for directed graph.
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