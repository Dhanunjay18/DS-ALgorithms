#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(int low, int high, vector<int> &arr){
    int i = low, j = high;
    while(i<j){
        while(arr[i] <= arr[low]) i++;
        while(arr[j] > arr[low]) j--;
        if(i<j) swap(arr[i], arr[j]);
        else swap(arr[low], arr[j]);
    }
    return j; 
}

void quickSort(int low, int high, vector<int> &arr){
    if(low < high){
        int j = partition(low, high, arr);
        quickSort(low, j-1, arr);
        quickSort(j+1, high, arr);
    }
}

int main(){
    int n = 8;
    vector<int> arr = {23,12,45,67,4,67,18,89};
    quickSort(0, n-1, arr);
    for(auto i: arr) cout<<i<<" ";
    return 0;
}