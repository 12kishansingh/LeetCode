// BFS+ dijkstra algo 
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0],v=flights[i][1],w=flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<vector<int>>q;
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        q.push({0,src,0});//stops_taken,node, distance covered
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it[0];
            int node=it[1];
            int currdis=it[2];
            if(stops>k)break;
            for(auto &x:adj[node]){
                int nbr=x.first;
                int wt=x.second;
                int newdis=currdis+wt;
                if(newdis<dis[nbr]){
                    dis[nbr]=newdis;
                    q.push({stops+1,nbr,newdis});
                }
            }
        }
        return dis[dst]==INT_MAX?-1:dis[dst];
    }
};
