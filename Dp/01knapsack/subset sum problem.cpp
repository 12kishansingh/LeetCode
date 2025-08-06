class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        bool dp[201][2001]; // dp[i][j] = true if sum j is possible with first i elements

        // Base case initialization
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true; // sum 0 is always possible (empty subset)
        }
        for (int j = 1; j <= sum; j++) {
            dp[0][j] = false; // non-zero sum not possible with 0 elements
        }

        // DP table filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];// there is true false instead of max use OR
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};
