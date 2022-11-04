#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/


class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int pairFound = 0;
        map<string, int> mp;
        int ans = 0;
        for(auto i: words){
            if(i[0]==i[1]){                
                if(mp[i]>0){
                    pairFound--;
                    ans += 4;
                    mp[i]--;
                }         
                else{
                    mp[i]++;
                    pairFound++;
                }
            }
            else{
                string s = i;
                reverse(s.begin(), s.end());
                if(mp[s]!=0){
                    mp[s]--;
                    ans += 4;
                }
                else{
                    mp[i]++;
                }
            }                       
        }    
        cout<<ans<<endl;
        return (pairFound!=0) ? ans + 2 : ans;
    }
};