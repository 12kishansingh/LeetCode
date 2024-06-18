// GFG and Coding Ninza
    void insertAtBotton(stack<int>&st,int element){
    if (st.empty()) {
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBotton(st, element);
    st.push(top);
}

    void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }
    int top=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBotton(stack,top);
}
