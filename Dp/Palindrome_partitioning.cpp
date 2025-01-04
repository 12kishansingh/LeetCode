class Solution {
public:
void solve(string &s,int i, vector<string> &curr, vector<vector<bool>>&dp,vector<vector<string>>&ans){
    if(i==s.size()){
        ans.push_back(curr);
        return;
    }
    for(int j=i;j<s.size();j++){
         if(dp[i][j]==true){
            curr.push_back((s.substr(i,j-i+1)));
            solve(s,j+1,curr,dp,ans);
            curr.pop_back();//backtracking
         }
    }
}
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                     if(l==2){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=dp[i+1][j-1]; 
                }
                }
            }
        }
        vector<vector<string>>ans;
        vector<string>curr;
             solve(s,0,curr,dp,ans);
             return ans;
    }
};
