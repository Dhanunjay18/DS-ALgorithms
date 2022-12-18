

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/


/*
    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    // Use stack 
    // Push elements into the stack until u find a arithmetic exp symbol
    // When u found any arithmetic exp then, pop the first two elements from stack 
    // Calculate the expression and again push into the stack for further operations.
    // Final answer will be in stack.top(). 
    stack<string> s;
    // 	cout << stoi("-11") + 1 << endl;
    for(auto i: tokens) {
        if(i!="+" and i!="-" and i!="*" and i!="/") {
            s.push(i);
            cout << s.top() << endl;
        }
        else {
            long long int a = stol(s.top());
            s.pop();
            long long int b = stol(s.top());
            s.pop();
            cout << a << " " << i << " " << b<<" = " ;
            if(i=="+") {
                s.push(to_string(a+b));
                cout << s.top() << endl;
            }
            if(i=="-") {
               s.push(to_string(b-a)); 
               cout << s.top() << endl;
            }
            if(i=="*") {
              s.push(to_string(a*b)); 
              cout << s.top() << endl;
            }
            if(i=="/") {
               s.push(to_string(b/a)); 
               cout << s.top() << endl;
            }
            
        }
    }
    return stol(s.top());
    }
};