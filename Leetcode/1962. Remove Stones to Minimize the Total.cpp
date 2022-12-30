
// https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Priority Queue by defaults adjusts it elements
        // OBSERVATION : If u frequently wants to sort the elements in any array, make use of Priority queue. 
        priority_queue<int> pq(piles.begin(), piles.end()); // Default : Large elment High Priority 
        while(k-- and !pq.empty()) {
            int t = pq.top();
            t -= t/2;
            pq.pop();
            pq.push(t);
        }
        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};