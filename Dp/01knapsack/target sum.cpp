class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        // If absolute target is greater than total sum or (sum + target) is odd
        if (abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }

        int t = (sum + target) / 2;

        int dp[21][2001]; 

        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // one way to make sum 0 (choose nothing)
        }
        for (int j = 1; j <= t; j++) {
            dp[0][j] = 0; // 0 elements can't make positive sum
        }

       
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][t];
    }
};
