// 29/30 passed at leetcode , some signed integer overflow
class Solution {
public:
    int change(int amt, vector<int>& coins) {
        int n = coins.size();
        if (amt == 0) return 1;
        if (n == 0) return 0;

       
        vector<vector<long long>> dp(n + 2, vector<long long>(amt + 2, 0));

       
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amt; j++) {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return (int)dp[n][amt];
    }
};
// correct
class Solution {
public:
const long long mod= 100000000003; // added this only 
    int change(int amt, vector<int>& coins) {
          int n = coins.size();
        if (amt == 0) return 1;
        if (n == 0) return 0;

       
        vector<vector<long long int>> dp(n + 2, vector<long long int>(amt + 2, 0));

       
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amt; j++) {
                if(coins[i-1] > j) {
                    dp[i][j]= dp[i-1][j];
                } else {
                    dp[i][j] = (dp[i-1][j]+dp[i][j-coins[i-1]])%mod;
                }
            }
        }
        return (int)dp[n][amt];
    }
};
