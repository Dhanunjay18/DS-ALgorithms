#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string,vector<string>> mp;
        for(int i=0; i<strs.size(); ++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;                        
    }
};