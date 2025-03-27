// using DFS

class Solution {
  public:
  bool dfs(vector<vector<int>>&adj,int i, vector<bool>&visited,int parent){
      
      visited[i]=true;
      
      for(auto x:adj[i]){
          if(x==parent)continue;
          if(visited[x])return true;
          
          if(dfs(adj,x,visited,i))return true;
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(),false);
       for(int i=0;i<adj.size();i++){
           if(!visited[i]&& dfs(adj,i,visited,-1))return true;
       }
       return false;
        
    }
};
// using BFS

class Solution {
  public:
  bool bfs(vector<vector<int>>&adj,int i, vector<bool>&visited){
      queue<pair<int,int>>q;
      q.push({i,-1});
      visited[i]=true;
      
      while(!q.empty()){
          pair<int,int>p=q.front();//{node,parent}
          q.pop();
          
          for(auto x:adj[p.first]){
              if(visited[x]==false){
                  visited[x]=true;
                  q.push({x,p.first});
              }
              else if(x!=p.second){//x!=parent
                  return true;
              }
          }
          
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(),false);
       for(int i=0;i<adj.size();i++){
           if(!visited[i]&& bfs(adj,i,visited))return true;
       }
       return false;
        
    }
};
