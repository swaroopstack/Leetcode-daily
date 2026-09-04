class MinStack {
public:
    stack<int> minst;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(minst.empty() || minst.top()>=value){
            minst.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(!minst.empty()){
            if(minst.top()==st.top()){
                minst.pop();
                st.pop();
            }
            else{
                st.pop();
            }
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */