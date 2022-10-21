#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
            /*
                Step 1 : From back search for the index 'f' where nums[i] < nums[i+1]
                Step 2 : If the position it not found then the array is in the sorted order then the next Permutation will be reverse of the list.
                Step 3 : If the index is found then from the back of the list, search for the first 'l' position where then nums[f] < nums[i]
                Step 4 : Now swap the numbers at the postions two indexes i.e, f and l,  that has found.
                Step 5 : Now, finally reverse the array from the first found index 'f' exclusive to last index reverse(f+1 -> n).
            */
            int n = nums.size();
            int f = -1;
            for(int i=n-2;i>=0;i--){
                    if(nums[i] < nums[i+1]){
                            f = i;
                            break;
                    }
            }
            if(f==-1) reverse(nums.begin(), nums.end()); // since , nextPermutation([3,2,1]) is [1,2,3]
            else{
                    int l;
                    for(int i = n-1; i>=0; i--){
                            if(nums[f] < nums[i]){
                                    l = i;
                                    break;
                            }                            
                    }
                    swap(nums[f],nums[l]);
                    reverse(nums.begin()+f+1, nums.end());
            }        
    }
};