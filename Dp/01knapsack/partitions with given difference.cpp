class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int sum = accumulate(arr.begin(), arr.end(), 0);

        // If sum + d is odd or sum < d, no valid partitions
        if ((sum + d) % 2 != 0 || sum < d) return 0;

        int t = (sum + d) / 2;
        int n = arr.size();

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        // Base case: sum 0 is possible with empty subset
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][t];
    }
};
