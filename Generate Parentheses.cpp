class Solution {
public:
vector<string>ans;
bool isvalid(string &s){
    int cnt=0;
    for(char &ch:s){
        if(ch=='(')cnt++;
        else cnt--;
        if(cnt<0)return 0;
    }
    return cnt==0;
}
 void solve(string &curr,int n){
            if(curr.length()==2*n){
                if(isvalid(curr)){
                    ans.push_back(curr);
                }
                return;
            }
            curr.push_back('(');
            solve(curr,n);
            curr.pop_back();
            curr.push_back(')');
            solve(curr,n);
            curr.pop_back();
            
 }
    vector<string> generateParenthesis(int n) {
        //recursion will take care of it
        string curr="";
         solve(curr,n);
         return ans;
    }

};
// another method whis faster than the above code 

class Solution {
public:
vector<string>ans;
 void solve(string &curr,int n,int open,int close){
            if(curr.length()==2*n){
                 ans.push_back(curr);
                return;
            }
            if(open<n){
            curr.push_back('(');
            solve(curr,n,open+1,close);
            curr.pop_back();
            }
            if(close<open){
            curr.push_back(')');
            solve(curr,n,open,close+1);
            curr.pop_back();
            }
            
 }
    vector<string> generateParenthesis(int n) {
        //recursion will take care of it
        int open=0,close=0;
        string curr="";
         solve(curr,n,open,close);
         return ans;
    }

};
