class Solution {
public:
    void edgeO(vector<vector<char>>& board, int i, int j, int rows, int column) {
        if(i<0 or j<0 or i>=rows or j>=column or board[i][j] != 'O') return;
        board[i][j] = 'Y';
        edgeO(board, i-1, j, rows, column);
        edgeO(board, i+1, j, rows, column);
        edgeO(board, i, j-1, rows, column);
        edgeO(board, i, j+1, rows, column);
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0) return;
        int column = board[0].size();

        for(int j=0; j<column; j++) {
            if(board[0][j] == 'O') // first row
                edgeO(board, 0, j, rows, column);
            if(board[rows-1][j] == 'O') // last row
                edgeO(board, rows-1, j, rows, column);
        }

        for(int i=0; i<rows; i++) {
            if(board[i][0] == 'O') // first column
                edgeO(board, i, 0, rows, column);
            if(board[i][column-1] == 'O') // last column
                edgeO(board, i, column-1, rows, column);
        }

     for(int i=0; i<rows; i++)
         for(int j=0; j<column; j++)
         {
             if(board[i][j] == 'O')
                 board[i][j] = 'X';
             if(board[i][j] == 'Y')
                 board[i][j] = 'O';
         }
    }
};
