#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n]; // [1,0,3,2,4,0,7]
    int leftMax[n],rightMax[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        leftMax[i] = rightMax[i] = arr[i];
    }
    for(int i=1;i<n;i++){   
        leftMax[i] = max(leftMax[i],leftMax[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i],rightMax[i+1]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += min(leftMax[i],rightMax[i]) - arr[i];
    }
    cout<<ans<<endl;
    return 0;
}
