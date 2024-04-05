class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        
        for(char &ch : s) {
            if(ans.size() > 0 && (ch + 32 == ans.back() || ch - 32 == ans.back())) {
                ans.pop_back();
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;    }
};
