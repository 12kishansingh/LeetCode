class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        // set MSB 
        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                for(int j=0;j<n;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }
      for(int j=1;j<n;j++){
        int cnt=0;
        for(int i=0;i<m;i++){
            if(grid[i][j]==0)cnt++;
        }
        int cntone=m-cnt;
        if(cnt>cntone){
            // flipping column 
            for(int i=0;i<m;i++){
                grid[i][j]=1-grid[i][j];
            }
        }
      }
      int ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            //int curr=grid[i][j]*pow(2,n-j-1);
            int curr=grid[i][j]<<(n-j-1);
            ans+=curr;
        }
        
      }
      return ans;
    }
};
