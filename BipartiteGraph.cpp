//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// https://leetcode.com/problems/possible-bipartition/description/

// } Driver Code Ends
class Solution {
    vector<int> color;
public:
    bool bfsCheck(int i, vector<int> adj[]) {
        /*
            
        */
        color[i] = 0;
        queue<int> q; 
        q.push(i);
        while(!q.empty()) {
            int node = q.front();
            for(auto it: adj[node]) {
                if(color[it]==-1) {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
            q.pop();
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Check for Bipartite or not
	    color.resize(V, -1);
	    for(int i=0; i<V; ++i) {
	        if(color[i]==-1) {
	            if(bfsCheck(i, adj)) continue;
	            return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends