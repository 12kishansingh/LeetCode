// giving tle --O(k^2 * n)
class Solution {
  public:
  int dp[1001][1001];
    int solve(int n,int k){
        if(k==0|| k==1)return k;
        if(n==1)return k;
        int mn=INT_MAX;
        if(dp[n][k]!=-1)return dp[n][k];
        for(int i=1;i<=k;i++){
            int temp=1+max(solve(n-1,i-1),solve(n,k-i));// break+ not break;
            mn=min(mn,temp);
        }
        return dp[n][k]=mn;
    }
    int eggDrop(int n, int k) {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

// using binary search to find best i 

class Solution {
public:
    int dp[1001][1001];

    int solve(int n, int k) {
        if (k == 0 || k == 1) return k;
        if (n == 1) return k;

        if (dp[n][k] != -1) return dp[n][k];

        int mn = INT_MAX;
        int low = 1, high = k;

        while (low <= high) {
            int mid = (low + high) / 2;

            int breakCase = solve(n - 1, mid - 1); // egg breaks
            int notBreakCase = solve(n, k - mid);  // egg survives

            int temp = 1 + max(breakCase, notBreakCase);
            mn = min(mn, temp);

            if (breakCase < notBreakCase) {
                // Need to go higher
                low = mid + 1;
            } else {
                // Need to go lower
                high = mid - 1;
            }
        }

        return dp[n][k] = mn;
    }

    int eggDrop(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};
