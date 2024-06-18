class Solution {
public:
string froot(string word,unordered_set<string>&st){
    for(int i=1;i<word.length();i++){
        string root=word.substr(0,i);//to check for each substring 
        if(st.count(root)){
            return root;
        }
    }
    return word;
}
    string replaceWords(vector<string>& d, string sen) {
        unordered_set<string>st(d.begin(),d.end());

        stringstream ss(sen);// string stream to tokenize each word in vector
        string word;
        string ans;

        while(getline(ss,word,' ')){//adding root to ans 
            ans+=froot(word,st)+' ';
        }
        ans.pop_back();// to remove the last space in sentence
        return ans;
    }
};
