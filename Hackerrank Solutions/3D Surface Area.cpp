#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/3d-surface-area/problem?isFullScreen=false

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+2, vector<int>(m+2, 0));
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> a[i][j];
        }
    }
    
    int ans = 2 * n * m;  // top and bottom area
    
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(a[i][j] > a[i-1][j]) ans += abs(a[i][j]-a[i-1][j]);  // front view 
            if(a[i][j] > a[i+1][j]) ans += abs(a[i][j]-a[i+1][j]);   // back view
            if(a[i][j] > a[i][j-1]) ans += abs(a[i][j]-a[i][j-1]);   // left view
            if(a[i][j] > a[i][j+1]) ans += abs(a[i][j]-a[i][j+1]);   // right view
        }        
    }
    
    cout << ans << endl;
    
    return 0;
}