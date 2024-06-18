//Topdown/Recursion+Memoization 
class Solution {
public:int dp[101];
    int solve(vector<int>&nums,int idx){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];//memoization
        int steal=nums[idx]+solve(nums,idx+2);
        int skip=solve(nums,idx+1);
        return dp[idx]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};
// Bottom Up approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        if(n==1)return nums[0];
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(steal,skip);
        }
        return dp[n];
    }
};
