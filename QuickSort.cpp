#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int low, int high, int arr[]){
    int i = low, j = high;
    while(arr[i] <= arr[low]) i++;
    while(arr[j] > arr[low]) j--;
    if(i<j) swap(arr[i], arr[j]);
    else swap(arr[low], arr[j]);
    return j; 
}

void quickSort(int low, int high, int arr[]){
    if(low < high){
        int j = partition(low, high, arr);
        quickSort(low, j-1, arr);
        quickSort(j+1, high, arr);
    }
}

int main(){
    int n = 7;
    int arr[n] = {7,6,5,4,3,2,1};
    quickSort(0, n-1, arr);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}