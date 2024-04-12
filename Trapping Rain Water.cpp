//for each index, leftmax and right find kiya, then take out area and sum it

class Solution {
public:
    int trap(vector<int>& h) {
       int n=h.size();
       vector<int> leftmax(n),rightmax(n);
       leftmax[0]=h[0];
       for(int i=1;i<n;i++){
        leftmax[i]=max(h[i],leftmax[i-1]);
       }
       rightmax[n-1]=h[n-1];
       for(int i=n-2;i>=0;i--){
        rightmax[i]=max(h[i],rightmax[i+1]);
       }
       int cnt=0;
       for(int i=0;i<n;i++){
        cnt+=min(leftmax[i],rightmax[i])-h[i];
       }
       return cnt;
    }
};
