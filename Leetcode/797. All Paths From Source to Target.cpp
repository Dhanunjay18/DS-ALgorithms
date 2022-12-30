class Solution {    
        vector<vector<int>> ans;
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int> vis, vector<int> temp, int n) {
        if(node==n-1) {
            ans.push_back(temp);
            return;
        }
        for(auto it: graph[node]) {   // Basically doing backtracking (Insert, Do Stuff, Delete)
            temp.push_back(it);       // Inserting 1 element
            dfs(it, graph, vis, temp, n);
            temp.pop_back();          // After operation done for that element
                                      // Popping out that element for further operations 
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        // Visited track will be seperate for all the edges from adj[0]
        ans.clear();
        int n = graph.size();
        for(auto it: graph[0]) {
            vector<int> temp;    // For every path, we create a new vector for paths
            temp.push_back(0);
            temp.push_back(it);  // These lines are basically pushing the initial edge from 0 to another vertex
            dfs(it, graph, vis, temp, n);
        }
        return ans;
    }
};