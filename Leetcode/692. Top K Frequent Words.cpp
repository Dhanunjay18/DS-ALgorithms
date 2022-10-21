#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 //  https://leetcode.com/problems/top-k-frequent-words/

class Solution {
    static bool cmp(pair<string,int> &a, pair<string,int> &b){
        if(a.second==b.second)
            return a.first < b.first;
        return a.second > b.second;
    }
public:    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> mp;
        for(auto i : words) mp[i]++;
        vector<pair<string,int>> vec;
        for(auto i : mp) vec.push_back(i);
        sort(vec.begin(), vec.end(), cmp);
        vector<string> ans;
        int i = 0;
        while(k--){
            ans.push_back(vec[i].first);
            i++;
        }    
        
        return ans;
    }
};