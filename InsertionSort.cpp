#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int arr[n];
        for(int i=0; i<n; ++i) cin >> arr[i];
        for(int i=1; i<n; ++i) {
            int curr = arr[i];
            int j = i - 1;
            while(j>=0 and arr[j]>curr) {
                arr[j+1] = arr[j];
                j--;
            }
            cout << ++j << " ";
            arr[j] = curr;
        }
        cout << endl;
    }
    return 0;
}
