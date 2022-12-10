#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// https://www.hackerrank.com/contests/smart-interviews/challenges/si-spiral-traversal-of-matrix/copy-from/1353234258


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) cin >> arr[i][j];
        }
        for(int i=0; i<(n/2)+1; ++i){ // We should start from diagonals ie; -44, 22 , .....
            int k = n-i-1;
            for(int j=i; j<n-i-1; ++j){     // Top row (ltr)
                cout << arr[i][j] << " ";
            }
            for(int j=i; j<n-i-1; ++j){     // Right Side Column (ttb)
                cout << arr[j][k] << " ";
            }            
            for(int j=n-i-1; j>i; --j){     // Bottom Row (rtl)
                cout << arr[k][j] << " ";
            }            
            for(int j=n-i-1; j>i; --j){     // Left Side Column (btt)
                 cout << arr[j][i] << " ";   
            }
        }
        if(n%2) cout << arr[n/2][n/2];
        cout << endl;
    }
    return 0;
}
