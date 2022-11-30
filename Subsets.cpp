#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void generateSubsets(vector<int> &arr, vector<vector<int>> &ans, vector<int> &curr, int idx){    
    ans.push_back(curr);
    for(int i=idx; i < arr.size();  i++){
        curr.push_back(arr[i]);
        generateSubsets(arr,ans,curr,i+1);
        curr.pop_back();
    }
    return;
}
int main()
{
    
    vector<int> arr = {1,2};
    
    vector<vector<int>> ans;
    vector<int> curr;
    generateSubsets(arr,ans,curr,0);
    for(auto i: ans){
        for(auto j: i) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}