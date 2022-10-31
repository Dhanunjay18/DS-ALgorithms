#include <bits/stdc++.h>

using namespace std;


// https://www.hackerrank.com/challenges/encryption/problem?isFullScreen=false
int main(){
    string s;
    cin>>s;
    int len =  s.size();
    int col = ceil(sqrt(len));
    
    string ans = "";
    
    for(int i=0; i<col; ++i){
        int temp = i;
        while(temp<s.size()){
            ans += s[temp];
            temp += col;
        }
        ans += " ";
    }    
    cout<<ans<<endl;
    return 0;
}