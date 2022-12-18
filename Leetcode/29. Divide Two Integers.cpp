
// https://leetcode.com/problems/divide-two-integers/description/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1) {   // For that edge case of having INT_MIN
            return INT_MAX;
        }
        long long int a = abs(dividend);
        long long int b = abs(divisor);
        long long int ans = 0;
        while(a-b >= 0) {
            long long int x = 0;
            while(a - (b<<1<<x) >=0 ) x++;   // Acutally doing a - ((b * 2) * 2^x)
            ans += 1 << x;   // doing ans = ans + (1 * 2^x)
            a -= b << x;     // doing a = a - (b * 2^x)
        }
        if(dividend<0 and divisor<0) return ans;
        else if(dividend<0 or divisor<0) return -1 * ans;
        return ans;
    }
};