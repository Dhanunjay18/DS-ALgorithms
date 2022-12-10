#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> arr(n,vector<int>(n));
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j) cin >> arr[i][j];
        }
        vector<int> ans;
        for(int i=n-1; i>=0; --i){
            int j = 0;
            int r = i;
            int c = j;
            int sum = 0;
            while(r<n and c<n){
                sum += arr[r++][c++];                
            }
            ans.push_back(sum);
        }
        for(int i=1; i<n; ++i){
            int j = 0;
            int r = i;
            int c = j;
            int sum = 0;
            while(r<n and c<n){
                sum += arr[c++][r++];                
            }
            ans.push_back(sum);
        }
        reverse(ans.begin(), ans.end());
        for(auto i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
