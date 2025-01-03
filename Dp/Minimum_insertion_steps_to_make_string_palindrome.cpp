// bottom up
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};

// recursion+memoization
class Solution {
public:
    int dp[501][501];
    int solve(string& s, int i, int j) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1);
        }

        return dp[i][j] = 1 + min(solve(s, i + 1, j), solve(s, i, j - 1));
    }
    int minInsertions(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size()-1);
    }
};
