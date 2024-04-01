// using stl
class Solution {
public:
    int lengthOfLastWord(string s) {
        int trail=s.find_last_not_of(' ')+1;
        s.erase(trail);
        int space=s.find_last_of(' ');
        return trail-space-1;
    }
};
//implementation/brute force
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool flag=0;
        int cnt=0;
        int n=s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]>='a'&& s[i]<='z'|| s[i]>='A'&& s[i]<='Z'){
                flag=1;
                cnt++;
            }
            else {
                if(flag==1)return cnt;
            }
        }return cnt;
    }
};
