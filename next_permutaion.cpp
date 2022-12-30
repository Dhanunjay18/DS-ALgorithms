#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> vec(9);
    iota(vec.begin(), vec.end(), 1);

    for(auto i: vec) cout << i << " ";

    
    return 0;
}