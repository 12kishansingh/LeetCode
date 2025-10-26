class Solution {
public:
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,vector<vector<int>>&a,int oldcolor,int color){

        int n=a.size();
        int m=a[0].size();
        if(i<0 || i>=n||j<0 || j>=m)return;
        
        if(a[i][j]!=oldcolor|| a[i][j]==color)return;
        a[i][j]=color;

        for(auto x:dir){
            int p=i+x[0];
            int q=j+x[1];
            dfs(p,q,a,oldcolor,color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       if(image[sr][sc]==color)return image;
       dfs(sr,sc,image,image[sr][sc],color);
       return image;
    }
};
