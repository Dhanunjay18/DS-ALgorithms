#include <bits/stdc++.h>
using namespace std;

//  https://leetcode.com/problems/count-sorted-vowel-strings/description/

// => MATHEMATICAL APPROACH USING PERM AND COMB
//   -------------------------------------
//   |((n+4) * (n+3) * (n+2) * (n+1))/24;|
//   -------------------------------------
class Solution {
public:
    int countVowelStrings(int n) {
       vector<vector<int>> dp(n+1, vector<int>(6));
       // actually make dp[1] = { 1 , 1 , 1 , 1 , 1}
       for(int i=1; i<=5; ++i) dp[1][i] = 1;
       // from 2 to n (inclusive) make calculate the value of dp[i]
       for(int i=2; i<=n; ++i){
            dp[i][1] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5];   // for dp['a']
            dp[i][2] = dp[i-1][2] + dp[i-1][3] + dp[i-1][4] + dp[i-1][5];  // -> dp['e']
            dp[i][3] = dp[i-1][3] + dp[i-1][4] + dp[i-1][5];     // -> dp['i']
            dp[i][4] = dp[i-1][4] + dp[i-1][5];  // dp['o']
            dp[i][5] = dp[i-1][5];   // dp['u']
        }
        int ans = 0;
        for(auto i: dp[n]) ans += i;
        return ans;
    }
};