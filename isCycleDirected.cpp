//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    // Take two arrays 1-> Visited and 2-> Path Visited 
    // WHILE DFS IF ANY NODE IS VISITED AND ITS PATH IS ALSO VISITED BEFORE THEN THE 
    // GRAPH IS SAID TO BE DIRECTED CYCLIC GRAPH
    bool dfsCheck(int vis[], int path[], int node, vector<int> adj[]) {
        vis[node] = 1;
        path[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfsCheck(vis, path, it, adj)) return true;
            }
            else if(path[it]==1) return true;
        }
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int path[V] = {0};
        for(int i=0; i<V; ++i) {
            if(!vis[i]) {
                if(dfsCheck(vis, path, i, adj)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends