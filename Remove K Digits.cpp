//Monotonic Stack
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans = ""; //it will act like a stack
        int n = num.length();
        
        for(int i = 0; i < n; i++) {
            
            while(ans.length() > 0 && ans.back() > num[i] && k > 0) {
                ans.pop_back();
                k--;
            }
            
            if(ans.length() > 0 || num[i] != '0') {
                ans.push_back(num[i]); //to avoid the case when we have preceeding zeros
            }
            
        }
        
        
        while(ans.length() > 0 && k > 0) {
            ans.pop_back();
            k--;
        }

        if(ans == "") {
            return "0";
        }
        
        return ans;
        
    }
};
