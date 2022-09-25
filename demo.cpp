#include <iostream>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int tt;
            cin>>tt;
            arr.push_back(tt);
        }
        vector<int> inter;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int mn = arr[j];
                int mx = arr[j];
                for(int k=i;k<=j;k++){
                    mn = min(mn,arr[j]);
                    mx = max(mx,arr[j]);
                }
                inter.push_back(mn*mx);
            }
        }        
        cout<<*min_element(inter.begin(),inter.end())<<" "<<*max_element(inter.begin(),inter.end())<<endl;
    }
	return 0;
}
