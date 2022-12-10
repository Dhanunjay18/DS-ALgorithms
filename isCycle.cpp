#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(vector<int> adj[], int vis[], int node, int parent){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(isCycleDFS(adj, vis, it, node)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}

bool isCyclBFS(vector<int> adj[], int vis[], int idx){
    vis[idx] = 1;
    queue<pair<int,int>> q;
    q.push({idx, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push({it, node});
            }
            else if(it!=parent) return true;
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> adj[n+1];
        for(int i=1; i<=m; ++i){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int vis[n+1];
        for(int i=1; i<=n; ++i)vis[i] = 0;
        bool flag = false;
        for(int i=1; i<=n; ++i){
            if(!vis[i]){
                if(isCycleDFS(adj, vis, i, -1)){
                    // cout << "Here" << endl;
                    flag = true;
                    break;   
                }
            }
        }
        (flag) ? cout << "No" << endl : cout << "Yes" << endl;
    }
    return 0;
}