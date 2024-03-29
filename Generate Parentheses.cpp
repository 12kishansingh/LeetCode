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
