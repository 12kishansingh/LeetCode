
class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& inrecur, int node) {
        // Mark the current node as visited and part of the recursion stack
        visited[node] = true;
        inrecur[node] = true;

        // Explore all neighbors of the current node
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor] && dfs(adj, visited, inrecur, neighbor)) {
                return true; // Cycle detected
            } else if (inrecur[neighbor]) {
                return true; // Cycle detected through recursion stack
            }
        }

        // Backtrack: unmark the node from recursion stack
        inrecur[node] = false;
        return false; // No cycle detected from this node
    }

    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false), inrecur(n, false);

        // Check for cycles starting from every node
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dfs(adj, visited, inrecur, i)) {
                return true; // Cycle found
            }
        }

        return false; // No cycles found
    }
};


class Solution {
public:
   

    bool isCyclic(vector<vector<int>>& adj) {
       queue<int>q;
       vector<bool>visited(adj.size(),false);
        
        vector<int>indegree(adj.size());
        for(int i=0;i<adj.size();i++){
            for(auto u:adj[i]){
                indegree[u]++;
            }
        }
        
        int cnt=0;
        for(int i=0;i<adj.size();i++){
            if(!indegree[i]){
                q.push(i);
                cnt++;
            }
        }
         // bfs-->khans algo
         
         while(!q.empty()){
             int curr=q.front();
             q.pop();
             for(auto v:adj[curr]){
                 indegree[v]--;
                 if(!indegree[v]){
                     cnt++;
                     q.push(v);
                 }
             }
         }
         
         return !(cnt==adj.size());
         
    }
};
