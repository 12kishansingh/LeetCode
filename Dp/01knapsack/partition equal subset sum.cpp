class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2) return false;

        int w = sum / 2;
        bool dp[201][10001]; // max sum can be 10000 based on constraints

        // Base cases
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true; // sum 0 is always possible
        }
        for (int j = 1; j <= w; j++) {
            dp[0][j] = false; // no sum > 0 possible with 0 elements
        }

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][w];
    }
};
