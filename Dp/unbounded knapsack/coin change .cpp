//recrusive

class Solution {
public:
unordered_map<int,int>dp;

int solve(vector<int>&a,int amt){
   if(amt==0){
    return 0;
   }
   if(dp.find(amt)!=dp.end()){
    return dp[amt];
   }
   int ans=INT_MAX;
   for(auto c:a){
    if(amt-c>=0){
        int res=solve(a,amt-c);
        if(res!=INT_MAX){
            ans=min(ans,1+res);
        }
    }
   }
   dp[amt]=ans;
   return ans; 
}
    int coinChange(vector<int>& coins, int amt) {
        
       int mx= solve(coins,amt);
       return (mx==INT_MAX)?-1:mx;
    }
};

// top down

class Solution {
public:
    int coinChange(vector<int>& coins, int amt) {
        int n = coins.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(amt + 1, INF));

        // Base case: 0 coins needed to make amount 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // Build table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amt; j++) {
                if (coins[i - 1] <= j) {
                    // Take it (unbounded) or skip it
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amt] == INF ? -1 : dp[n][amt];
    }
};

