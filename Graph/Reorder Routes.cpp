class Solution {
public:
void dfs(int node, vector<vector<int>>&frd,vector<vector<int>>&bwd,int &ans,vector<int>&visited){
    visited[node]=1;
    //forward neighbor need to change the direction 
    for(int x:frd[node]){
        if(!visited[x]){
            ans++;
            dfs(x,frd,bwd,ans,visited);
        }
    }
    for(int x:bwd[node]){
        if(!visited[x]){
            dfs(x,frd,bwd,ans,visited);
        }
    }
}
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>frd(n),bwd(n);
        vector<int>visited(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0];
            int b=connections[i][1];
            frd[a].push_back(b);
            bwd[b].push_back(a);
        }
        int ans=0;
        dfs(0,frd,bwd,ans,visited);
        return ans;
    }
};
