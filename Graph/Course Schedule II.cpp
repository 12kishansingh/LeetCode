// bfs -- topological sort ---> Kahn's Algo
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto x:edges){
            adj[x[1]].push_back(x[0]);
        }
        vector<int>indgre(n);
        for(int i=0;i<adj.size();i++){
            for(auto u:adj[i]){
                indgre[u]++;
            }
        }
        queue<int>q;
        for(int i=0;i<adj.size();i++){
            if(indgre[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(auto v:adj[u]){
                indgre[v]--;
                if(indgre[v]==0){
                    q.push(v);
                }
            }
        }
        if(ans.size()!=n)return {};// if there is cycle 
        return ans;
    }
};
// dfs based
class Solution {
public:
vector<int>ans;
bool dfs(unordered_map<int,vector<int>>&adj, vector<bool>&visited,vector<bool>&inrecur,int u){
    visited[u]=true;
    inrecur[u]=true;
    
    for(auto v:adj[u]){
        if(!visited[v] && dfs(adj,visited,inrecur,v)){
            return true;
        }
        else if(inrecur[v]){
            return true;
        }
    }
    ans.push_back(u);
    inrecur[u]=false;// unmark the node from the recursion stack, backtracking 
    return false;
}

    vector<int> findOrder(int n, vector<vector<int>>& a) {
         unordered_map<int,vector<int>>adj;
      for(int i=0;i<a.size();i++){
        int u=a[i][0];
        int v=a[i][1];
        adj[u].push_back(v);
      }  
      vector<bool>visited(n,false);
      vector<bool>inrecur(n,false);
      for(int i=0;i<n;i++){
        if(!visited[i]&& dfs(adj,visited,inrecur,i)){
            return {};// cycle found 
        }
      }

      return ans;//
    }
};
