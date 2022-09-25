#include<iostream>
using namespace std;
void print_subarrrays(int arr[],int start,int end,int n){
    /*
        1.Check if are going out from the array :
                i.e, end>=n or end==n (since,end always increment by 1 only)
        2.If our current start is less than or equal to the current end then,
            print the elements from start to the end.
            Now, recursively increase the start pointer and recursively call the subarray_function
            i.e, by passing start as ++start and end as end itself.
        3.Else i.e, our current start is greater than the end index then,
            recursively call the subarray function by passing start as 0,end as end+1.
    */
    if(end==n) return;
    if(start<=end){
        cout<<endl;
        for(int i=start;i<=end;i++){
            cout<<arr[i]<<" ";
        }
        print_subarrrays(arr,start+1,end,n);
    }
    else{
        print_subarrrays(arr,0,end+1,n);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_subarrrays(arr,0,0,n);
    return 0;
}