// Can be done in many ways : 
//  -> Conventional Soritng technique
//  -> Count array techniques to count 0's, 1's, 2's
//  -> DUTCH NATIONAL FLAG ALGORITHM

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int arr[12] = {1,0,1,2,0,1,2,0,0,1,0,2};
    int mid,high,low;
    mid = low = 0;
    high = sizeof(arr)/sizeof(int) - 1;
    // Steps : 
    // -> Initially take three variables/Pointers low,mid,high
    // -> Initialize the pointers to : 
    //    1. low and mid to start of the array
    //    2. high pointer to the end of the array 
    // -> Do the following operations on array until mid becomes greater than high
    //      If the value at the arr[mid]
    //      case 0 : swap it with value at arr[low] and increment both low and mid
    //      case 1 : just increment the value of the mid pointer
    //      case 2 : swap it with value at arr[high] and only decrement the high pointer 
            // A way to remeber is after the end of the operations :
            //  All the values left to low pointer will be 0.
            //  All the values right to high pointer will be 2.
            //  All the values from low to high will be 1.
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    // cout<<low<<" "<<mid<<" "<<high<<endl;
    for(auto i: arr) cout<<i<<" ";    
    return 0;
}
