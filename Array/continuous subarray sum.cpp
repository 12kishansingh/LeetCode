class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        m[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int r=sum%k;// when multiple of k is added remainder remains same 
            if(m.find(r)!=m.end()){
                if((i-m[r])>=2){
                    return true;
                }
            }
            else{
                m[r]=i;
            }
        }
        return false;
    }
};
