#include<vector>
#include<iostream>
using namespace std;
int main(){
    int m,n,cap;
    cin>>m>>n;
    int t[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>t[i][j];
        }
    }
    cin>>cap;
    int f = 0;
    for(int i=0;i<m;i++){
        if(i!=m-1){
            if(t[i][2] > t[i+1][1]){
                int ts = t[i][0]+t[i+1][0];
                if(ts>cap){
                    f = 1;
                    break;
                }
            }
        }
    }
    if(f)
        cout<<"false"<<endl;
    else
        cout<<"true"<<endl;
    return 0;
}