#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//  https://leetcode.com/problems/integer-to-roman/



class Solution {
public:
    string intToRoman(int num) {        
        string ones[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string huns[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thns[] = {"","M","MM","MMM"};
        
        return thns[(num/1000)] + huns[(num/100)%10] + tens[(num/10)%10] + ones[(num%10)];
    }
};