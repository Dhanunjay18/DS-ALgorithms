/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int first = -1;
int last = -1;
int ans = 0;
void reverseString(string str,int index){
    if(index == 0){
        cout<<str[0];
        return;
    }
    cout<<str[index];
    reverseString(str,index-1);
}

void findFirstLastOccurence(string str,char ch,int index){
    if(index == str.length()){
        cout<<"First : "<<first<<endl;
        cout<<"Last : "<<last<<endl;
        return;
    }
    if(str[index] == ch){
        if(first == -1){
            first = last = index;
        } else {
            last = index;
        }
    }
    findFirstLastOccurence(str,ch,index+1);
}

void towerOfHonoi(int n,string source, string buffer, string destination){
    ans++;
    if(n==1) return;
    towerOfHonoi(n-1,source,destination,buffer);
    towerOfHonoi(n-1,buffer,source,destination);
}

int main()
{
    string str = "Dhanunjay";
    // reverseString(str,str.length()-1);
    // findFirstLastOccurence(str,'D',0);
    towerOfHonoi(4,"A","B","C");
    cout<<ans<<endl;
    return 0;
}
