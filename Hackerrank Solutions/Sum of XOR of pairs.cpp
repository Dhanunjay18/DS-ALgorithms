#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;

// https://www.hackerrank.com/contests/smart-interviews/challenges/si-sum-of-xor-of-pairs/problem


int main() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll a[n];
        for(ll i=0; i<n; ++i) cin >> a[i];
        ll ans = 0;
        for(ll i=0; i<32; ++i) {
            ll one = 0, zero = 0;
            for(ll j=0; j<n; ++j) {
                ((a[j]>>i)&1) ? one++ : zero++;   // Basically Counting no of ones and zeroes at 
                // Position or bit i for every element in array
            }            
            ll valueAti = one * zero * pow(2, i);   // (#1 * #0 * 2^i)  => will result value of ans at that postion (ith position)
            ans += 2 * valueAti;    
        }
        cout << ans << endl;
    }
    return 0;
}
