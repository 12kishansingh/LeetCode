class Solution {
public:
    int dp[1001][1001];
    bool isPal[1001][1001];

    void precompute(string &s) {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) {
                        isPal[i][j] = true;
                    } else {
                        isPal[i][j] = isPal[i + 1][j - 1];
                    }
                }
            }
        }
    }

    int solve(string &s, int i, int j) {
        if (i >= j || isPal[i][j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPal[i][k]) { // cut only if left part is palindrome
                ans = min(ans, 1 + solve(s, k + 1, j));
            }
        }
        return dp[i][j] = ans;
    }

    int palPartition(string &s) {
        memset(dp, -1, sizeof(dp));
        memset(isPal, 0, sizeof(isPal));
        precompute(s);
        return solve(s, 0, s.size() - 1);
    }
};
