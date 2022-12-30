// https://leetcode.com/problems/single-threaded-cpu/description/

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<pair<pair<int,int>, int>> vec(n);
        for(int i=0; i<n; ++i) {
            vec[i] = {{tasks[i][0], tasks[i][1]}, i};
        }
        sort(vec.begin(), vec.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // for min-heap {processing_time, index}
        long long int time = 0, idx = 0;
        vector<int> ans;
        while(idx<n or pq.size()) {
            if(pq.empty()) time = max(time, (long long int)vec[idx].first.first);  // IF cpu is in idle state
            while(idx<n and time>=vec[idx].first.first) {   // Keeep on pusshing the elements into the pq whose 
                                                            // enque time is lesss than or equal to totalTime 
                pq.push({vec[idx].first.second, vec[idx].second});
                idx++;
            }
            time += pq.top().first;   // Adding curr processing time to total time
            ans.push_back(pq.top().second);  // Getting index and adding it to ans
            pq.pop();
        }
        return ans;
    }
};