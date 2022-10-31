#include<vector>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {

        vector<pair<int,int>> vec;

        for(int i=0; i<plant.size(); ++i)
            vec.push_back({grow[i], plant[i]});
        sort(vec.begin(), vec.end());

        // {{1,3},{2,1},{3,4}}        
        int res = 0;
        for(auto i: vec){
            res = max(i.first, res) + i.second;
            // cout<<i<<" "<<j<<" "<<res<<endl;
        }
        return res;
    }
};