// User function Template for C++

class Solution {
  public:
  bool dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&path){
      visited[node]=1;
      path[node]=1;
      for(int x: adj[node]){
          if(!visited[x]&& dfs(x,adj,visited,path)){
              return true;
          }
          else {
              if(path[x])return true;
          }
      }
      path[node]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    vector<int>ans;
    vector<int>visited(V),path(V);
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,adj,visited,path);
        }
    }
    for(int i=0;i<V;i++){

            int curr=dfs(i,adj,visited,path);
            if(!curr){
                ans.push_back(i);
            }
    }
    
    return ans;
    }
};
