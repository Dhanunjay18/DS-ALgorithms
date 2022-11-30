#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:
    
    bool check(int i, int V, vector<int> adj[], vector<bool> &vi){
        vi[i] = true;
        queue<pair<int,int>> q;
        q.push({i, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                if(!vi[it]){
                    vi[it] = true;
                    q.push({it, node});
                }
                else if(it!=par) return true;
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vi(V, false);
        for(int i=0;i<V; ++i){
            if(!vi[i]){
                if(check(i, V, adj, vi)) return true;
            }
        }
        return false;
    }
};