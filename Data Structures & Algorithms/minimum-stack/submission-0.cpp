class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        nums.push(val);
        if (mins.size() == 0) {
            mins.push(val);
        } else {
            mins.push(min(val, mins.top()));
        }
    }
    
    void pop() {
        nums.pop();
        mins.pop();
    }
    
    int top() {
        return nums.top();
    }
    
    int getMin() {
        return mins.top();
    }

private:
    stack<int> nums;
    stack<int> mins;
};
