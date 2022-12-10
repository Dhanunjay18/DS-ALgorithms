#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    int expandFromMiddle(string s, int start, int end){
        while(start>=0 and end<s.size() and s[start]==s[end]){
            start--;
            end++;
        }
        return end - start - 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        for(int i=0; i<n; ++i){
            int len1 = expandFromMiddle(s, i, i);   // for string like "racear"
            int len2 = expandFromMiddle(s, i, i+1); // for string like "aabbaa"
            int len = max(len1, len2);
            cout << len << endl;
            if(len>(end-start)){
                start = i - (len-1)/2;  // (len - 1) becoz to reduce index out of bounds problem
                end = i + len/2;
            }
        }        
        //                |            |           
        return s.substr(start, (end + 1 - start));     // substr(start, len)
        //                ^           ^  
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    }
};