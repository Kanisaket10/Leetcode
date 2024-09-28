class MinStack {
public:
    vector<int> st;
    multiset<int>s;

    MinStack() {}
    
    void push(int val) {
        st.push_back(val);
        s.insert(val);
       
    }
    
    void pop() {
        int topele = st.back();
        st.pop_back();
        s.erase(s.find(topele));
    }
    
    int top() {
        return st.empty() ? -1 : st.back();
    }
    
    int getMin() {
       return *s.begin(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */