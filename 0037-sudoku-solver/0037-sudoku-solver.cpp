class Solution {
    int rows[9] = {0}, columns[9] = {0}, boxes[9] = {0};
public:
    bool solve(vector<vector<char>>& board, int r, int c)
    {
        if(r>=9)
            return true;

        if(c>=9)
            return solve(board, r+1, 0);

        if(board[r][c]!='.')
            return solve(board, r, c+1);

        for(int i{0}; i<9; i++)
        {
            int box = r/3*3 + c/3;
            int mask = 1<<i;
            if(!(rows[r]&mask or columns[c]&mask or boxes[box]&mask) )
            {
                rows[r] |= mask;
                columns[c] |= mask;
                boxes[box] |= mask;

                board[r][c] = i + '1';

                if(solve(board, r, c+1))
                {
                    return true;
                }

                rows[r] &= ~mask;
                columns[c] &= ~mask;
                boxes[box] &= ~mask;

                board[r][c] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        ios::sync_with_stdio(false);
        for(int i{0}; i<9; i++)
        {
            for(int j{0}; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    int box = i/3*3 + j/3;
                    int mask = 1<<(board[i][j] - '1');

                    rows[i] |= mask;
                    columns[j] |= mask;
                    boxes[box] |= mask;
                }
            }
        }
        solve(board,0, 0);
    }
};