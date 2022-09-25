#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    map<int,int> mp;
    for(int i=0;i<n;i++){
        // int t;
        cin>>a[i];
        mp[a[i]]++;
    }
    for(auto i: mp)
        cout<<i.first<<" "<<i.second<<endl;
    return 0;
}