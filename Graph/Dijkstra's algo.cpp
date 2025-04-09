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
