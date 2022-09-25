#include <iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<vector<int>> org(n);
    int p1 = 0;
    int p2 = 2 * n - 2;
    int nt = n;
    vector<int> temp(2*n-1,n);
    for(int i=0;i<n;i++){
        for(int j=p1;j<=p2;j++){
            temp[j] = nt;
        }
        org[i] = temp;
        p1++; p2--; nt--;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n-1;j++){
            cout<<org[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<2*n-1;j++){
            cout<<org[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
