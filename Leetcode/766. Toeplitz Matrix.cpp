#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/toeplitz-matrix/


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int col = matrix[0].size();
        // [1,2,3,4,5,1,2,3,9,5,1,2]
        vector<int> flat;
        for(auto i: matrix) for(auto j: i) flat.push_back(j);
        for(int i=0; i<flat.size()-col; ++i){
            if(i%col!=col-1){
                if(flat[i]!=flat[i+col+1]) return false;
            }
        }
        return true;
    }
};