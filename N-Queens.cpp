class Solution {
public:
    vector<vector<string>> ans;
    int N;
    bool check(vector<string> board, int row, int col) {
        for (int i = row - 1; i >= 0; i--) { // for same columm
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0;
             i--, j--) { // diagonal left and up
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < N;
             i--, j++) { // diagonal right and up
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string> board, int row) {
        if (row >= N) { // means we've already filled queens in above rows
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < N; j++) { // column
            if (check(board, row, j)) {
                board[row][j] = 'Q';
                solve(board, row + 1);
                board[row][j] = '.'; // backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.')); // create board
        N = n;
        solve(board, 0); // row =0 start filling
        return ans;
    }
};
