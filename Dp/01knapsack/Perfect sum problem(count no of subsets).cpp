class Solution {
  public:
    int perfectSum(vector<int>& arr, int sum) {
        int n = arr.size();
        int dp[201][2001];  

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

       
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = 0;  
        }

        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j]  + dp[i - 1][j - arr[i - 1]]; 
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
        
    }
};
