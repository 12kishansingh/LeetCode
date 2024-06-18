//Recursoion+Memoization -top down approach
class Solution {
public:
typedef long long ll;
ll n;
ll dp[100001][2];
ll solve(int i,vector<int>&nums,bool flag){
    if(i>=n){
        return 0;
    }
    if(dp[i][flag]!=-1){
        return dp[i][flag];
    }
    ll skip=solve(i+1,nums,flag);
    ll val=nums[i];
    if(flag==false){
        val=-val;
    }
 ll take=solve(i+1,nums,!flag)+val;
    return dp[i][flag]=max(take,skip);
}




    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,true);
    }
};
