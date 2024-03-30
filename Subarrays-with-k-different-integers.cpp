class Solution {
public:
// return total subarrays in which unique count<=k
    int slidingwindow(vector<int>&a,int k){
        unordered_map<int,int>mp;
        int n=a.size();
        int j=0,i=0;
        int cnt=0;
        while(j<n){
            mp[a[j]]++;
            while(mp.size()>k){
                mp[a[i]]--;
                if(mp[a[i]]==0){
                    mp.erase(a[i]);
                }i++;
            }
            cnt+=(j-i+1);j++;
        }
        return cnt;
   
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
    return slidingwindow(nums,k)-slidingwindow(nums,k-1);
    }
};
