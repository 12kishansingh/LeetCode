
// dijkestra algorithm used
class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        
        while(!pq.empty()){
            auto pr=pq.top();pq.pop();
            int currdis=pr[0],x=pr[1],y=pr[2];
            for(int i=0;i<4;i++){
                int ii=x+dx[i],jj=y+dy[i];
                if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
                int newdis=max(currdis,abs(heights[x][y]-heights[ii][jj]));
                if(newdis<dist[ii][jj]){
                    dist[ii][jj]=newdis;
                    pq.push({dist[ii][jj],ii,jj});
                }
            }
        }
        return dist[n-1][m-1];
    }
};
