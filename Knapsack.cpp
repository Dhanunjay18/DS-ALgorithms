#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<double, double> a,pair<double, double> b){
    return (a.first/a.second) > (b.first/b.second);
}

int main(){
    double n = 6;
    // cin>>n;
    vector<pair<double,double>> data {{5,5}, {5,3}, {10,5}, {7,7}, {9,8}, {18,4}}; double t;
    vector<float> ratio(n);
    // for(double i=0; i<n; ++i){
    //     cin>>t;
    //     data[i].first = t;
    //     cin>>t;
    //     data[i].second = t;
    //     ratio[i] = data[i].first/data[i].second;
    // }
    double m = 18;
    // cin>>m;
    sort(begin(data), end(data), cmp);
    double total = 0;
    double capacity = m;
    for(double i=0; i<n; ++i){
        if(data[i].second <= capacity){
            cout<<"PRofit : "<<data[i].first<<endl;
            total += data[i].first;
            capacity -= data[i].second;
        }
        else{
            double ratio = data[i].first/ data[i].second;
            // cout<<"Cap "<<total<<endl;
            cout<<"PRofit : "<<data[i].first<<endl;
            total += capacity * ratio;
            capacity = 0;
            break;
        }
    }
    cout<<total<<endl;
    return 0;
}