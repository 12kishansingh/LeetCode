// bottom up 
class Solution {
  public:
    int dp[1001][1001];

    int solve(vector<int>& wt, vector<int>& val, int w, int i) {
        if (i == 0 || w == 0) {
            return 0;
        }
        if (dp[i][w] != -1) {
            return dp[i][w];
        }
        if (wt[i - 1] <= w) {
            return dp[i][w] = max(val[i - 1] + solve(wt, val, w - wt[i - 1], i - 1),
                                  solve(wt, val, w, i - 1));
        } else {
            return dp[i][w] = solve(wt, val, w, i - 1);
        }
    }

    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        memset(dp, -1, sizeof(dp));
        return solve(wt, val, W, val.size());
    }
};


//top down

class Solution {
  public:
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        int n = val.size();
        int dp[1001][1001];

        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= W; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {
                if (wt[i - 1] <= j) {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]],
                                   dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
    }
};
