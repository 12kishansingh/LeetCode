class Solution {
  public:
  void dfs(vector<vector<int>>& adj,vector<bool>&visited,int u,stack<int>&st){
      visited[u]=true;
      
      for(int &v:adj[u]){
          if(!visited[v]){
              dfs(adj,visited,v,st);
          }
      }
      st.push(u);
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        
        vector<bool>visited(adj.size(),false);
        stack<int>st;
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                dfs(adj,visited,i,st);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

//dfs
class Solution {
public:
deque<int>dq;
void dfs(int node, vector<int>&visited,vector<vector<int>>&adj){
    visited[node]=1;
    for(int x:adj[node]){
        if(!visited[x]){
            dfs(x,visited,adj);
        }
    }
    dq.push_front(node);
}
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V);
       for(auto x:edges){
           adj[x[0]].push_back(x[1]);
           
       }
       vector<int>visited(V);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,visited,adj);
           }
       }
       vector<int>ans;
       for(int x:dq){
           ans.push_back(x);
       }
       return ans;
    }
};

// using bfs--khans algo
class Solution {
  public:
  void bfs(vector<vector<int>>& adj,vector<bool>&visited,int u,stack<int>&st){
      
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        vector<int>indegree(adj.size());
        for(int i=0;i<adj.size();i++){
            for(auto u:adj[i]){
                indegree[u]++;
            }
        }
        // fill queue with indegree 0
        queue<int>q;
        for(int i=0;i<adj.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
        
       
       
    }
};
