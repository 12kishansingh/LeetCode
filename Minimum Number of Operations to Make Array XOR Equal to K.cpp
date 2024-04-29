class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x=0;
        for(int i=0;i<nums.size();i++){
            x^=nums[i];
        }
        int req=k^x;
        int ans=__builtin_popcount(req);
        return ans;
    }
};
