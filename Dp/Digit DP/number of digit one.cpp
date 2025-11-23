class Solution {
public:
int dp[11][2][20];
int solve(string &s,int idx,int tight,int cnt){
    if(idx==s.size()){
        return cnt;
    }
    if(dp[idx][tight][cnt]!=-1)return dp[idx][tight][cnt];
    int limit=(tight==1)?s[idx]-'0':9;//eg: 4569- so at idx 0 we cant take number greater than 4, so limit is 4, but if we are taking 3, than tight will 0 and we can take any number (0-9)
    int ans=0;
    for(int i=0;i<=limit;i++){
        int cnt1=cnt+((i==1)?1:0);
        ans+=solve(s,idx+1,(tight&(i==s[idx]-'0')),cnt1);// if tight is 1 previously it will remain 1 and if it is 0 then it will remain 0
    }
    return dp[idx][tight][cnt]=ans;
}
    int countDigitOne(int n) {
     string r=to_string(n);
     memset(dp,-1,sizeof(dp));
     int right=solve(r,0,1,0);
     return right;
      // if some range have been given like f(l,r);
     //   string l=to_string(n);
     // memset(dp,-1,sizeof(dp));
     // int left=solve(l,0,1,0);
     // return right-left;
    
    }

};
