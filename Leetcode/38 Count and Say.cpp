// https://leetcode.com/problems/count-and-say/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for(int i=2;i<=n;++i){
            string curr = prev;
            int p = 0;
            string ans = "";
            while(curr[p]!=NULL){
                int cnt = 1;
                p++;
                while(curr[p]==curr[p-1]){
                    p++;
                    cnt++;
                }
                ans = ans + to_string(cnt) + curr[p-1];
            }
            prev = ans;
        }
        return prev;
    }
};