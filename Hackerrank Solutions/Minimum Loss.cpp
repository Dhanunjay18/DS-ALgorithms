#include <bits/stdc++.h>

using namespace std;

// https://www.hackerrank.com/challenges/minimum-loss/problem

int main(){
    
    int n;
    cin>>n;
    vector<long> price;
    for(long i=0; i<n; ++i){
        long t;
        cin>>t;
        price.push_back(t);
    }
    
    // before sorting map the indexes with values for further steps
    map<long,long> mp;
    for(long i=0; i<price.size(); ++i){
        mp[price[i]] = i;
    }
    // 5
    // 20 7 8 2 5
    long minLoss = INT_MAX;
    // Now sort the list
    sort(begin(price), end(price));
    //After sorting it would become
    // 2 5 7 8 20
    // Now iterate through price from reverse
    // Check whether they are in order or not by using mp
    for(long i=price.size()-2; i>=0; --i){
        if(mp[price[i]]>mp[price[i+1]])
            minLoss = min(minLoss, price[i+1]-price[i]);
    }
    cout<<minLoss<<endl;
    return 0;
}