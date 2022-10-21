#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//  https://www.hackerrank.com/challenges/magic-square-forming/problem

bool check(vector<int> flat){
    //Check Row Sum
    int rsum = 0;
    bool flag = true;
    for(int i=0; i<flat.size(); ++i){
        rsum += flat[i];
        if(i%3==2){
            if(rsum!=15) return false;
            rsum = 0;
        }
    }
    //Check Col Sum 
    int csum[3] ={0};
    for(int i=0; i<flat.size(); ++i){
        csum[i%3] += flat[i];
    }
    for(auto i: csum) if(i!=15) return false;
    
    //Check Diagonal Sum 
    // 0 1 2
    // 3 4 5
    // 6 7 8
    if((flat[0]+flat[4]+flat[8])!=15 or (flat[2]+flat[4]+flat[6])!=15) return false;
    return true;    
}

int transform(vector<int> m, vector<int> n){
    int total = 0;    
    for(int i=0; i<m.size(); ++i) {
        total += (m[i]-n[i]); // Need to use abs() funtcion 
    }
    return total;
}

int formingMagicSquare(vector<vector<int>> s) {
    int minCost = INT_MAX;
    vector<int> flat;
    for(auto i: s) for(auto j: i) flat.push_back(j);
    /*
        5 3 4 1 5 8 6 4 2
        
        5 3 4
        1 5 8
        6 4 2
        
        
        8 3 4
        1 5 9
        6 7 2
    */
    // Now we need to check each Permutation of the flat array to transform
    vector<int> n = {1,2,3,4,5,6,7,8,9};
    if(check(flat)) return 0; 
    while(next_permutation(n.begin(),n.end())) { // Takes 9!
        if(check(n)){
            minCost = min(minCost,transform(flat,n));
        }
    }
    return minCost;
}
