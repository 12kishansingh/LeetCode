// bellman ford- relax all edges V-1 times, v is no of vertex 

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dis(V,INT_MAX);
        dis[src]=0;
        //relaxation v-1 times
        for(int i=0;i<V-1;i++){
            for(auto edge:edges){
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(dis[u]==INT_MAX)continue;
                
                int newdis=dis[u]+w;
                if(newdis<dis[v]){
                    dis[v]=newdis;
                }
            }
        }
        // check if nodes are again begin relaxed, if yes, then there exist negative wt cycle
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dis[u]==INT_MAX)continue;
            
            int newdis=dis[u]+w;
            if(newdis<dis[v]){
                return {-1};
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX){
                dis[i]=1e8;
            }
        }
        return dis;
    }
};
