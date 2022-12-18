

// https://leetcode.com/problems/implement-queue-using-stacks/description/

// As push is most commonly used operation so, make push fuction to perform O(1) TC

class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> input, output;  // It is O(1) TC becoz, at most of the time pop() and peek() done in O(1) TC
    void push(int x) {
        input.push(x);   // Just push into input for push operation
    }
    
    int pop() {
        if(!output.empty()) {   // If output stack is not empty just pop the element from the output and return it
            int data = output.top();
            output.pop();
            return data;
        }
        // If it is emty(output stack) then push all input elements into the output stack and pop() from the output stack
        while(!input.empty()) {   
            output.push(input.top()); 
            input.pop();
        }
        int data = output.top();
        output.pop();
        return data;
    }
    
    int peek() {
        if(!output.empty()) {    // For peek if the output stack is not empty then just return its top element 
            return output.top();
        }
        // If it is empty(Output stack ) then just make push all elements form input stack to output stack and return output stack's top element
        while(!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
    
    bool empty() {
        return output.empty() and input.empty();   // Just return the boolean value if both the stacks are empty then , return true : else return fasle;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */