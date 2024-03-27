class Solution {
public:// use index as number as 1<=a[i]<=n:
    vector<int> findDuplicates(vector<int>& a) {
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            int num=abs(a[i]);
            int index=num-1;
            if(a[index]<0){
                ans.push_back(num);
            }
            else{
                a[index]*=-1;
            }
        }return ans;
    }
};
