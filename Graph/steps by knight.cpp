class Solution {
  public:
  vector<vector<int>>dir={{-2,1},{-2,-1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
  int bfs(int sx,int sy,int tx,int ty,int n){
      vector<vector<int>>visited(n,vector<int>(n));
      queue<pair<int,int>>q;
      q.push({sx,sy});
      visited[sx][sy]=1;
      int cnt=0;
      while(!q.empty()){
          int t=q.size();
          while(t>0){  
              pair<int,int>p=q.front();
              q.pop();
              int x=p.first,y=p.second;
              if(x==tx&& y==ty){
                  return cnt;
              }
              for(int i=0;i<dir.size();i++){
                  int currx=x+dir[i][0];
                  int curry=y+dir[i][1];
                  if(currx>=0 && curry>=0&& currx<n && curry<n&& visited[currx][curry]==0){
                      visited[currx][curry]=1;
                      q.push({currx,curry});
                  }
              }
              t--;
          }
          cnt++;
      }
      return cnt;

  }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
      int sx=n-knightPos[1];
      int sy=knightPos[0]-1;
      int tx=n-targetPos[1];
      int ty=targetPos[0]-1;
      return bfs(sx,sy,tx,ty,n);
      
      
        
    }
};
