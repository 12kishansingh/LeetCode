class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int>st;
        unordered_set<int> idx;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    idx.insert(i);
                }else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            idx.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(idx.find(i)==idx.end())ans.push_back(s[i]);
        }
        return ans;
        
    }
};
