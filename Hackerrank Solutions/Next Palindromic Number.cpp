#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void nextPalindrome(long long int n){
    string s = to_string(n);
    string firstHalf;
    string firstHalfCopy;
    int num;
    if(s.size()%2==0){
        firstHalf = s.substr(0,(s.size())/2);        
        firstHalfCopy = firstHalf;
        reverse(firstHalf.begin(), firstHalf.end());
        num = stoi(firstHalfCopy+firstHalf);
    }
    else{
        firstHalf = s.substr(0,(s.size()/2));
        char midOne = s[(s.size()/2)];
        firstHalfCopy = firstHalf;
        reverse(firstHalf.begin(), firstHalf.end());
        num = stoi(firstHalfCopy+midOne+firstHalf);
    }
    if(num>n){
        cout<<num<<endl;
    }
    else{
        long long int x = s.size()/2; 
        n = n / pow(10, x);
        n = (n+1) * pow(10, x);
        nextPalindrome(n);   
    }
}

int main() {
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        if(n<9){
            cout<<n+1<<endl;
            continue;
        }
        nextPalindrome(n);
    }
    return 0;
}
