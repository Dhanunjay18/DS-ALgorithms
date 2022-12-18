
// https://leetcode.com/problems/daily-temperatures/description/

/*
    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int,int>> s;    // stack of {value, index}
        for(int i=n-1; i>=0; --i) {
            // Keep on popping out of element from stack  {else condition}
            // until any element temp[i] satisfies the given constraint :
            //         -> Assign ans[i] to the distance between current index and 
            //              satisfied constraint i.e, (s.top().second - currentIndex)
            //         -> Push the current {value, index} pair into the stack and break the iteration.
            // ONE EDGE CASE WOULD BE : If the stack is empty, there is no higher element right side to it ,
            //                          so make the ans for that index as '0'

            while(!s.empty()) {
                if(temp[i] < s.top().first) {
                    ans[i] = abs(i-s.top().second);
                    s.push({temp[i], i});
                    break;
                }
                else {
                    s.pop();
                }
            }
            if(s.empty()) {
                s.push({temp[i], i});
                ans[i] = 0;
            }
        }
        // OBSERVATION : For any element in the temp, the values in the stack will be either
        //               GREATER THAN OR EQUAL to the current element. 
        return ans;
    }
};