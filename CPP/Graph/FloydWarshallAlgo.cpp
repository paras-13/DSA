// Floyd Warshall Algorithm
// Time Complexity: O(n^3);
// The problem is to find the shortest distance between every pair of vertces:
/*
Floyd Warshall is a multi source path algorithm and it also help us to detect negative edge weight graph*/
#include <iostream>
#include <vector>
#define INF INT_MAX
using namespace std;
class Graph
{
private:
	vector<vector<pair<int, int>>> adj;
	vector<vector<int>> dist;
	int V;

public:
	Graph(int x)
	{
		this->V = x;
		adj.resize(x);
		dist.resize(V, vector<int>(V, INF));
	}
	void addEdge(int u, int v, int w)
	{
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<vector<int>> floydWarshall();
};

vector<vector<int>> Graph ::floydWarshall()
{
	for (int u = 0; u < V; u++)
	{
		dist[u][u] = 0;
		for (auto [v, w] : adj[u])
			dist[u][v] = w;
	}

	// FLoyd Warshall
	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (dist[i][k] != INF && dist[k][j] != INF)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	return dist;
}
int main()
{
	int v, e;
	cout << "Enter number of vertices: ";
	cin >> v;
	cout << "Enter number of edges: ";
	cin >> e;
	cout << "Enter weighted edges: ";
	Graph g1(v);
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g1.addEdge(u, v, w);
	}
	vector<vector<int>> res = g1.floydWarshall();
	cout << "Multi Source Shortest Path from each node: " << endl;
	for (int i = 0; i < v; i++)
	{
		cout << "Source: " << i << endl;
		cout << "Nodes: => ";
		for (int k = 0; k < v; k++)
			cout << k << " ";
		cout << endl;
		cout << "Dist:  => ";
		for (int j = 0; j < v; j++)
			cout << res[i][j] << " ";
		cout << "\n\n";
	}
}

// Floyd Warshall Algorithm--> Multi sources algorithm which works in O(n^3)
// It use a weight matrix for processing
// It is also used to detect negative weight cycle
// Can work with both directed and undirected graphs
// Can works with negative weight edges
