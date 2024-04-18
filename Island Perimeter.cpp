//DFS 

class Solution {
public:
int m,n,length;
void dfs(vector<vector<int>>& grid,int i,int j){
    if(i<0 || i>=m|| j<0 || j>=n|| grid[i][j]==0){
        length++;
        return;
    }
    if(grid[i][j]==-1){
        return;
    }
    grid[i][j]=-1;
    dfs(grid,i+1,j);
    dfs(grid,i-1,j);
    dfs(grid,i,j+1);
    dfs(grid,i,j-1);

}
    int islandPerimeter(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();length=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j);
                    return length;
                }
            }
        }
        return -1;
    }
};
// intuitive approach,just checking if it i+1,j,{i,j+1),.... is out of bound or zero and increase the count
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& a) {
        int cnt=0;
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==1){
                    if(j+1>=m || a[i][j+1]==0)cnt++;
                    if(i-1<0 || a[i-1][j]==0)cnt++;
                    if(i+1>=n || a[i+1][j]==0)cnt++;
                    if(j-1<0 || a[i][j-1]==0)cnt++;
                }
            }
        }
        return cnt;
    }
};
