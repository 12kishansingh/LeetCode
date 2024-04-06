//Approach 1- use of stack 
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
//Approach 2- Check the array from left to right, remove characters that do not meet the property mentioned above, same idea in backward way.
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // left to right
        int open=0;string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z')ans.push_back(s[i]);
            else if(s[i]=='('){
                ans.push_back(s[i]);open++;
            }
            else if(open>0){
                ans.push_back(s[i]);
                open--;
            }
        }
        //right to left
        int close=0;
        string final_ans="";
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]>='a'&& ans[i]<='z')final_ans.push_back(ans[i]);
            else if(ans[i]==')'){
                final_ans.push_back(ans[i]);close++;
            }
            else if(close>0){
                final_ans.push_back(ans[i]);
                close--;
            }
        }
        reverse(final_ans.begin(),final_ans.end());
        return final_ans;
    }
};
