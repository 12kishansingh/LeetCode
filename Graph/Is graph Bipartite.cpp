// bfs
class Solution {
public:
bool checkbfs(vector<vector<int>>&graph,vector<int>&color,int u,int currcolor){
    queue<int>q;
    q.push(u);
    color[u]=currcolor;
    
    while(!q.empty()){
        int curr=q.front();
        q.pop();

        for(auto v:graph[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            else if(color[v]==-1){
                q.push(v);
                color[v]=1-color[curr];
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(checkbfs(graph,color,i,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};
// dfs
class Solution {
  public:
  bool bipartitedfs(vector<vector<int>>&adj,vector<int>&color,int u,int currcolor){
      color[u]=currcolor;
      
      for(auto v:adj[u]){
          
          if(color[v]==color[u])return false;
          
          if(color[v]==-1){
              int colorofv=1-currcolor;
              if(bipartitedfs(adj,color,v,colorofv)==false){
                  return false;
              }
          }
      }
      return true;
  }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>color(n,-1);
        //red=1,green=0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if( bipartitedfs(adj,color,i,1)==false)return false;
            }
            
        }
        return true;
    }
};
