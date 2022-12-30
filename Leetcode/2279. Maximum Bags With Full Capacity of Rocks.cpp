
// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int ar) {
        int n = c.size();
        vector<int> diff(n);
        for(int i=0; i<n; ++i) {
            diff[i] = c[i] - r[i];
        }   
        // GRREDY APPROACH : 
        // Sort the diff according in asc order
        // Make the operation such that u gain max by using addRocks
        // ie, if(diff[i]<=addRocks) => c++ and addRocks[i] -= diff[i];
        int ans = 0;
        sort(diff.begin(), diff.end());
        for(auto i: diff) {
            cout << ar << " " << i << endl;
            if(i<=ar) {
                ans++;
                ar -= i;
                continue;
            }         
            break;               
        }                
        return ans;
    }
};