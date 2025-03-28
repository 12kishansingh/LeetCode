// bfs
class Solution {
public:
int n;
void bfs(int u,vector<bool>&visited,vector<vector<int>>& isConnected){
    queue<int>q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i=0;i<isConnected.size();i++){
            if(!visited[i]&& isConnected[u][i]==1)
               bfs(i,visited,isConnected);
            
        }
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int cnt=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,isConnected);cnt++;
            }
        }
        return cnt;

    }
};
class Solution {
public:
void dfs(int i,vector<bool>&visited,vector<vector<int>>&isConnected){
    visited[i]=true;

    for(int v=0;v<isConnected.size();v++){
        if(!visited[v]&& isConnected[i][v]==1){
            dfs(v,visited,isConnected);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int cnt=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);cnt++;
            }
        }
        return cnt;

    }
};
class Solution {
public:
void bfs(int u,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
    queue<int>q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto i:adj[curr]){
            if(!visited[i])
               bfs(i,visited,adj);
            }
        }
    }

int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
    
        int cnt=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(i,visited,adj);cnt++;
            }
        }
        return cnt;

    }
};
