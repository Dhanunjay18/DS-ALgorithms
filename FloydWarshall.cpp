#include <bits/stdc++.h>
using namespace std;

#define V 3

#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int dist[][V])
{
	
	int i, j, k;
	for (k = 0; k < V; k++) { // For every node we need to check all possible paths 
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				if (dist[k][j] != INF and dist[i][k] != INF) // This is done only if there is edge between i and j
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	cout << "The following matrix shows the shortest "
			"distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (dist[i][j] == INF)
				cout << "INF"
					<< " ";
			else
				cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	int graph[V][V] = { { 0, 8, 5 },
						{ 3, 0, 8 },
						{ INF, 2, 0} };
	floydWarshall(graph);
	return 0;
}