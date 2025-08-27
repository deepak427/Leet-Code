class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> row;
            unordered_set<char> col;
            unordered_set<char> box;
            for (int j = 0; j < 9; ++j) {
                if (row.find(board[i][j]) != row.end() && board[i][j] != '.')
                    return false;
                row.insert(board[i][j]);
            }
            for (int j = 0; j < 9; ++j) {
                if (col.find(board[j][i]) != col.end() && board[j][i] != '.')
                    return false;
                col.insert(board[j][i]);
            }
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cout << board[j + ((i / 3) * 3)][k + ((i % 3) * 3)];
                    if (box.find(board[j + ((i / 3) * 3)][k + ((i % 3) * 3)])!=box.end() && board[j + ((i / 3) * 3)][k + ((i % 3) * 3)] != '.')
                        return false;
                    box.insert(board[j + ((i / 3) * 3)][k + ((i % 3) * 3)]);
                }
            }
        }
        return true;
    }
};