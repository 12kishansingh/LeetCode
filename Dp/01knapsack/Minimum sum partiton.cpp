class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i];

        // dp[i][j] = whether we can get sum j using first i elements
        bool dp[n + 1][sum + 1];

        // Initialize base cases
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int j = 1; j <= sum; j++) dp[0][j] = false;

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int mn = INT_MAX;

        // Only need to consider subset sums up to sum/2
        for (int j = 0; j <= sum / 2; j++) {
            if (dp[n][j]) {
                mn = min(mn, sum - 2 * j);
            }
        }

        return mn;
    }
};
