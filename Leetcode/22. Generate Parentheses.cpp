
// https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    void find (vector<string> &ans, int n,string s, int open, int close) {
        if(s.size() == 2*n) {   // if size of string is comleted 
            ans.push_back(s);
            return;
        }
        if(open < n) find(ans, n, s + "(", open+1, close);
        if(close < open) find(ans, n, s + ")", open, close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        find(ans, n, "", 0, 0); // {ans, n, string, open, close}
        return ans;
    }
};