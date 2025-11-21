/*bfs/dfs -> traversal in the tree/ graph

apart from traversal --> work related to grouping or particular node is part of which graph, 

dsu is kindaa traversal only but also doing grouping

to detect cycle in undirected graph

mst(kruksal algo)

to count the no. of components in disconnected graph

find()--> recursion -> path compression technique

union()--> union by rank (parent[leader_b]=leader_a);
-> merging smaller group to bigger group is more efficient as less no. of recursive calls will be there in the find() fuction.
*/
class DSU{

private:
vectro<int>parent,rank;
public:
DSU(int n){
  parent.resize(n);
  rank.resize(n,1);
  for(int i=0;i<n;i++)parent[i]=i;
}

int find(int n){
  if(parent[n]==n)return n;
  // path compression 
  return parent[n]==find(parent[n]);
}

void union(int a,int b){
int leaderA=find(a);
int leaderB=find(b);
if(leaderA!=leaderB){
  if(rank[leaderA]<rank[leaderB]){
  parent[leaderA]=leaderB;
    rank[leaderB]+=rank[leaderA];
  }
  else{
  parent[leaderB]=leaderA;
    rank[leaderA]+=rank[leaderB]
  }
}
}

};

