#include<iostream>
using namespace std;
int ans = 0;
void towerOfHonoi(int n, char src, char hp, char dest){
    if(n==1){
        ans++;
        cout<<"Moved "<<n<<" to "<<src<<" -> "<<dest<<endl;
        return;
    }
    towerOfHonoi(n-1, src, dest, hp);
    ans++;
    cout<<"Moved "<<n<<" to "<<src<<" -> "<<dest<<endl;
    towerOfHonoi(n-1,hp,src,dest); 
}


int main(){
    int n = 1;
    towerOfHonoi(n,'A','B','C');
    cout<<ans<<endl;
    return 0;
}