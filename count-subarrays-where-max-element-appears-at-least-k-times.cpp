class Solution {
public://SLIDING WINDOW TEMPLATE
    long long countSubarrays(vector<int>& nums, int k) {
        int max=*max_element(nums.begin(),nums.end());// max number in vector using stl
        int i=0,j=0;
        long long ans=0;
        int cnt=0;
        while(j<nums.size()){
            if(nums[j]==max){
                cnt++;
            }
            while(cnt>=k){
                ans+=(nums.size()-j);
            
            if(nums[i]==max){
                cnt--;
            }i++;
        }j++;
    }
    return ans;
    }
};
