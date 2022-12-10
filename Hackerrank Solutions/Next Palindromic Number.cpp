#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void nextPalindrome(long long int n){
    string s = to_string(n);
    string firstHalf = s.substr(0,(s.size())/2);
    string firstHalfCopy = firstHalf;
    reverse(firstHalf.begin(), firstHalf.end());
    int num;
    if(s.size()%2==0){
        num = stoi(firstHalfCopy+firstHalf);
    }
    else{
        char midOne = s[(s.size()/2)];
        num = stoi(firstHalfCopy+midOne+firstHalf);
    }
    if(num>n){
        cout<<num<<endl;
    }
    else{  // Basic Idea is to add trailing zeroes at the end of (firstHalfCopy+1)
        long long int x = s.size()/2; 
        n = n / pow(10, x);
        n = (n+1) * pow(10, x);
        nextPalindrome(n);   

        // Strings approach
        /*
                long long int k;
                if(sz%2) k = stoi(fh+s[sz/2]);
                else k = stoi(fh);
                k++;
                string temp = to_string(k);
                for(long long int i=0; i<sz/2; ++i) temp += "0";
                nextPalindrome(stoi(temp));
        */
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
