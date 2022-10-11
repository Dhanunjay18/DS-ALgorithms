#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum[n*(n+1)/2];
    int p = 0;
    int max_Sum = arr[0];
    for(int i=0;i<n;i++){
        int s = 0;
        for(int j=i;j<n;j++){
            s += arr[j];
            sum[p++] = s;
            max_Sum = max(max_Sum,s);
        }
    }
    for(int i=0;i<n*(n+1)/2;i++){
        cout<<sum[i]<<" ";
    }
    cout<<"\n"<<"Max Sum = "<<max_Sum;
    return 0;
}


// KADANE'S  ALGORITHM
// 1. Initialize maxSum = arr[0] and sum = 0
// 2. Iterate through the given arrray and do :
        // -> Add current indexed array value to the sum
        // -> If sum gets negative make the sum = 0
        // -> And lastly update the maxSum = max(sum,maxSum)

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;++i)    cin>>arr[i];
//     int maxSum = arr[0] , sum = 0;
//     for(int i=0;i<n;++i){
//         sum += arr[i];
//         if(sum<0)   sum = 0;
//         maxSum = max(sum,maxSum);
//     }
//     cout<<maxSum<<endl;
// }