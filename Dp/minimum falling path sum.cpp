// Recursion + Memoization ---dp
class Solution {
public:
int n;
int dp[201][201];
int solve(int col,int row,vector<vector<int>>& grid){
    if(row==n-1){
        return grid[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int result=INT_MAX;
    for(int nextcol=0;nextcol<n;nextcol++){
        if(nextcol!=col){
            result=min(result,solve(nextcol,row+1,grid));
        }
    }
    return dp[row][col]=result+grid[row][col];

}
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        int res=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            res=min(res,solve(i,0,grid));
        }
        return res;
    }
};
