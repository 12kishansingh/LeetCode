class solution {
public:
vector<int>dijkstra(int V,vector<vector<int>>adj,int S){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>pq;

  vector<int>ans(V,INT_MAX);
  ans[s]=0;
  pq.push({0,s});

  while(!pq.empty()){
    int d=pq.top().first;
    int node=pq.top().second;
    pq.pop();

    for(auto &v:  adj[node]){
      int adjnode=v[0];
      int weight=v[1];

      if(d<+weight<ans[adjnode]){
        ans[adjnode]=d+weight;
        pq.push({d+weight,adjnode});
      }
    }
  }
  return ans;
  
}
};

//GFG
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto x:edges){
            int u=x[0],v=x[1],w=x[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dis(V,INT_MAX);
        dis[src]=0;
        
        // min heap: (distance,node)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        
        while(!pq.empty()){
            auto[d,u]=pq.top();pq.pop();
            if(d>dis[u])continue;
            
            for(auto x: adj[u]){
                int v=x.first;
                int w=x.second;
                if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    pq.push({dis[v],v});
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX)dis[i]=-1;
        }
        return dis;
    }
};
