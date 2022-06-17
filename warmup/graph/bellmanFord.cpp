/* single source shortest path.*/

# include <bits/stdc++.h>
using namespace std;

void bellmanFord(vector<vector<int>> &edges, int nodeCount, int source){
	vector<int> dist(nodeCount, INT_MAX);
	dist[source] = 0;
	int u, v, wt;
	bool cycle = false;
	
	// relaxing all edges nodeCount - 1 times:
	for(int i = 1; i <= nodeCount - 1; i++){
		for(int j = 0; j < edges.size(); j++){
			u = edges[j][0], v = edges[j][1], wt = edges[j][2];
			if(dist[u] != INT_MAX && dist[v] > dist[u] + wt)
				dist[v] = dist[u] + wt;
		}
	}
	
	// checking whether the graph contains negative edge weight cycle or not:
	for(int j = 0; j < edges.size(); j++){
		u = edges[j][0], v = edges[j][1], wt = edges[j][2];
		if(dist[u] != INT_MAX && dist[v] > dist[u] + wt){
			cout << "Graph contains negative cycle" << endl;
			cycle = true;
			break;
		}
	}
	
	if (cycle == false) {
		for (int i = 0; i < nodeCount; i++) 
			std::cout << "0 to " << i << " cost: " << dist[i] << std::endl;
	}
}

int main(){
	int nodeCount;
	int edgeCount;
	cin >> nodeCount;
	cin >> edgeCount;
	vector<vector<int>> edges;
	for(int i = 0; i < edgeCount; i++){
		vector<int> curEdge(3);
		cin >> curEdge[0];	// u
		cin >> curEdge[1];	// v
		cin >> curEdge[2];	// wt
		edges.push_back(curEdge);
	}
	bellmanFord(edges, nodeCount, 0);
	return 0;
}
