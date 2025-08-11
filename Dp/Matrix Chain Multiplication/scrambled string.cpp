

class Solution {
  public:
  
  unordered_map<string,bool>dp;
  
  bool solve(string a,string b){
    
      if(a.compare(b)==0)return true;
      
      if(a.size()<=1)return false;
      
      string key=a+"|"+b;
      if(dp.find(key)!=dp.end())return dp[key];
       // Pruning: check if both strings have same chars
      string x=a,y=b;
      sort(x.begin(),x.end());
      sort(y.begin(),y.end());
      if(x!=y)return dp[key]=false;
      
       int n=a.size();
      
       bool f=false;
     
     for(int i=1;i<=n-1;i++){
         // there is swapping 
         if(solve(a.substr(0,i),b.substr(n-i,i))&& 
                           solve(a.substr(i,n-i),b.substr(0,n-i))){
             f=true;
             break;
         }
         // there is no swapping 
         if(solve(a.substr(0,i),b.substr(0,i))&& 
                            solve(a.substr(i,n-i),b.substr(i,n-i))){
             f=true;
             break;
         }
     }
     
     return dp[key]=f;
      
  }
    bool isScramble(string a, string b) {
        // code here
         if(a.size()!=b.size())return false;
      
         if(a.empty()&& b.empty())return true;
         
         return solve(a,b);
        
    }
};
