#include <cmath>
#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// https://www.hackerrank.com/contests/smart-interviews/challenges/si-swap-bits/copy-from/1353314553

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s = "";
        ll temp  = n;
        while(temp){
            s += to_string(temp&1);
            temp /= 2;
        }
        for(ll i=0; i<s.size(); i+=2){
            if(i==s.size()-1){
                char k = s[i];
                s[i] = '0';
                s += k;
            }
            else swap(s[i], s[i+1]);
        }
        ll ans = 0;
        for(ll i=0; i<s.size(); ++i){
            if(s[i]=='1') ans += pow(2, i);
        }
        cout << ans << endl;
    }
    return 0;
}
