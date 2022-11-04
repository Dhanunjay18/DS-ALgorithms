#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/lilys-homework/problem


int lilysHomework(vector<int> arr) {
    vector<int> temp, temp2;
    map<int, int> mp, mp2;
    int j = 0;
    for(auto i: arr){
        temp.push_back(i);
        temp2.push_back(i);
        mp[i] = j;
        mp2[i] = j;
        j++;
    }
    sort(temp.begin(), temp.end());
    int cnt1=0, cnt2=0;
    int n = arr.size();
    for(int i=0; i<n; ++i){
        if(temp[i]!=arr[i]){       
            // temp[i] will be fixed     
            int idx = mp[temp[i]];            
            mp[arr[i]] = idx;
            swap(arr[i], arr[idx]);
            cnt1++;
        }
    }
    int k = 0;
    sort(temp.begin(), temp.end(), greater<int>());
    for(int i=0; i<n; ++i){
        if(temp[i]!=temp2[i]){            
            int idx = mp2[temp[i]];            
            mp2[temp2[i]] = idx;
            swap(temp2[i], temp2[idx]);
            cnt2++;
        }
    }
    
    for(auto i: mp){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<"---------------------------------"<<endl;
    for(auto i: mp2)
        cout<<i.first<<" "<<i.second<<endl;
    cout<<cnt1<<" "<<cnt2<<endl;
    return min(cnt1, cnt2);
}