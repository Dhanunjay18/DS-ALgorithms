#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; ++i){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    reverse(arr.begin(), arr.end());
    for(int i=0; i<n; ++i){
        if(arr[i]!=9){
            arr[i] += 1;
            break;
        }
        else{
            if(i==n-1){
                arr[i] = 0;
                arr.push_back(1);
            }else arr[i] = 0;
        }
    }
    reverse(arr.begin(), arr.end());
    for(auto i: arr) cout<<i<<" ";
    return 0;
}