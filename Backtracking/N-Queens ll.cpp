class Solution {
public:
unordered_set<int> col, leftDia, rightDia;
int cnt=0;
 
void recur(int i, vector<vector<char>> &s,int n) {
    if (i >= n) {
        cnt++;
        return;
    }
    for (int j = 0; j < n; j++) { // for each column in ith row
        int rdia = i + j;
        int ldia = i - j;
        if (col.count(j) || rightDia.count(rdia) || leftDia.count(ldia))
            continue;

      
      //s[i][j] = 'q';
        col.insert(j);
        leftDia.insert(ldia);
        rightDia.insert(rdia);

       
        recur(i + 1, s,n);

      // backtraking
        //s[i][j] = '.';
        col.erase(j);
        leftDia.erase(ldia);
        rightDia.erase(rdia);
    }
}
    int totalNQueens(int n) {
        
        vector<vector<char>>s(n,vector<char>(n,'.'));

        recur(0,s,n);
        return cnt;
    }
};
