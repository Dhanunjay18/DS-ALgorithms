class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mainXor = 0;
        // Do Xor for all the numbers in the given array 
        // By doing this xor we will get the Xor value of actual two values to be identified (mainXor = first ^ second)
        for(auto i: nums) mainXor ^= i;
        // Check for the first set bit position
        int bit = 0;
        int temp = mainXor;
        while(temp) {
            if(temp&1) break;
            temp >>= 1;
            bit++;
        }
        // Now do xor for every element which has the bit's as 1
        int first = 0;
        for(auto i: nums) {
            if((i>>bit)&1) first ^= i;
        }
        int second = mainXor ^ first;  // Do apply the commutaive law on xors
        return vector<int>{first, second};
    }
};