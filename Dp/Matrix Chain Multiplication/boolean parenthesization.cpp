
class Solution {
public:
    int dp[101][101][2]; // dp[i][j][0] => ways for 'F', dp[i][j][1] => ways for 'T'

    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ans = 0;
        for (int k = i + 1; k <= j - 1; k += 2) { // operator positions
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue) ans += lt * rt;// boolean maths & no of ways calculation
                else ans += lt * rf + lf * rt + lf * rf;
            }
            else if (s[k] == '|') {
                if (isTrue) ans += lt * rt + lt * rf + lf * rt;
                else ans += lf * rf;
            }
            else if (s[k] == '^') { // XOR
                if (isTrue) ans += lt * rf + lf * rt;
                else ans += lt * rt + lf * rf;
            }
        }

        return dp[i][j][isTrue] = ans;
    }

    int countWays(string &s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1, true); // ways to get True
    }
};


