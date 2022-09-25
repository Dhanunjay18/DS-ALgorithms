#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int cnt=0;
void generateSubsequence(int idx,vector<int> &seq,int n,vector<int> arr){
    if(idx>=n){
        cout<<endl<<++cnt<<" -> ";
        for(int i=0;i<seq.size();i++)
            cout<<seq[i]<<" ";
        return;
    }
    seq.push_back(arr[idx]);
    generateSubsequence(idx+1,seq,n,arr);
    seq.pop_back();
    generateSubsequence(idx+1,seq,n,arr);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    vector<int> seq;
    generateSubsequence(0,seq,n,arr);
    // string arr;
    // cin>>arr;
    // string seq;
    // int n = arr.size();
    // generateSubsequence(0,seq,n,arr);
    // return 0;
}