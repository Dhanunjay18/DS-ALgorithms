#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Job {
    public:
    int id, deadline, profit;
};

void display(Job obj[], int n){
    cout<<endl<<"ID\t"<<"Peofit\t"<<"Weight"<<endl;
    for(int i = 0; i<n; ++i){
        cout<<obj[i].id<<"\t"<<obj[i].profit<<"\t"<<obj[i].deadline<<endl;
    }
}

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

pair<int,int> solve(Job obj[], int  n){
    sort(obj, obj+n, cmp);
    int maxDeadline = INT_MIN;
    for(int i = 0; i<n; ++i){
        maxDeadline = max(obj[i].deadline, maxDeadline);
    }

    int slot[maxDeadline + 1];
    for(auto &i: slot) i = -1;
    int cntJobs = 0, jobProfit = 0;

    for(int i=0; i<n; ++i){
        for(int j=obj[i].deadline; j>0; --j){
            if(slot[j]==-1){
                slot[j] = i;
                jobProfit += obj[i].profit;
                cntJobs++;
                break;
            }
        }
    }
    return make_pair(cntJobs, jobProfit);
}

int main(){
    int n = 7;
    Job obj[n] = {{1,3,20},{2,1,15},{3,1,10},{4,3,7}, {5,1,5}, {6,3,3}, {7,2,10}};
    // for(int i=0; i<n; ++i){
    //     cin>>obj[i].id>>obj[i].deadline>>obj[i].profit;        
    // }
    // display(obj, n);
    pair<int, int> ans = solve(obj, n);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}