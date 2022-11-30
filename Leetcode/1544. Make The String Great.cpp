#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
    string makeGood(string s) {
        vector<char> ans;
        ans.push_back(s[0]);
        for(int i=1; i<s.size(); ++i){
            if(ans.size()==0){
                ans.push_back(s[i]);
                continue;
            }
            char prev = ans[ans.size()-1];
            char curr = s[i];
            if((prev-'a')==(curr-'A') or (prev-'A')==(curr-'a')){
                ans.pop_back();
                continue;
            }
            ans.push_back(s[i]);
        }      
        string k(ans.begin(), ans.end());  
        return k;
    }
};


/* Python Solution */

/*
class Solution:
    def makeGood(self, s: str) -> str:
        ans = []
        for i in s:
            if len(ans)==0:
                ans.append(i)
                continue
            prev = ans[len(ans)-1]
            curr = i
            if (ord(prev)-65==ord(curr)-97) or (ord(prev)-97==ord(curr)-65):
                ans.pop()
                continue
            ans.append(curr)
        return ''.join(ans)
            
*/