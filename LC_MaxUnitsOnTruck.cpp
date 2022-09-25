#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> &v1, vector<int> &v2){
    return v1[1] > v2[1];
}
int main()
{
    vector<vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}};
    int truckSize = 10;
    sort(boxTypes.begin(), boxTypes.end(), comparator);


    int ans = 0;
    for(auto iter: boxTypes){
        truckSize -= iter[0];
        int k = iter[0];
        if(truckSize<0)
            k = k + truckSize;
        ans += k * iter[1];
        if(k!=iter[0])
            break;
    }

    cout<<ans<<endl;
    return 0;
}
