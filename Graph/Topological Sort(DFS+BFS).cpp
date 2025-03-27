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
