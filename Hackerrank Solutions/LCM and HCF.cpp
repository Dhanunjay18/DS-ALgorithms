#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/contests/smart-interviews/challenges/si-lcm-and-hcf/submissions/code/1353235952

int main() {
    int t;
    cin >> t;
    while(t--){
        long long int a, b;
        cin >> a >> b;
        long long int mn = min(a, b);
        long long int mx = max(a, b);
        int r;
        do{
            r = mx % mn;
            mx = mn;
            mn = r;
        } while(r);
        long long int lcm = (a*b)/mx;
        cout << lcm << " " << mx << endl;
    }
    return 0;
}