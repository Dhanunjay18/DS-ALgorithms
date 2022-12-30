

// https://leetcode.com/problems/possible-bipartition/description/

class Solution {
    vector<int> color;
public:
    bool checkCycle(int curr, vector<int> adj[]) {
        // Inititally assign one color to the current node
        // The color array basically works as visisted array but it has two values : or we may call as two colors
        color[curr] = 1;
        queue<int> q;
        q.push(curr);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(color[it]==-1) {   // If the node is not yet colored 
                // then just assign opposite color of parent node
                    color[it] = !color[node];
                    q.push(it);
                }
                // If it is colored and it is same as its parent node then
                // IT is not a Bipartite Graph (return false)
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // basic intution is to check for bipartite graph in the given graph
        /*
            BIPARTITE GRAPH : 
                -> We should color the graph with 2 colors such that :
                    => No 2 adjacent nodes must have same colors.
                OBSERVATION : 
                -> A linear graph with no cycles is always a Bipartite Graph
                -> A graph with cycle of even length is considered as Bipartite graph
                -> A graph with odd length is not a Bipartite graph
        */
        vector<int> adj[n+1];
        color.resize(n+1, -1);
        for(auto i: dislikes) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1; i<=n; ++i) {
            if(color[i]==-1) {
                if(checkCycle(i, adj)) continue;
                return false;
            }
        }
        return true;
    }
};