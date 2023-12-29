#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

    bool isPossible(int row, int col, char num, vector<vector<char>>& board)
    {
        // we have 3 conditions to check, the entire row, the entire col, and the entire 3*3 matrix
        for(int i = 0; i<9; i++)
        {
            // checking the entire row
            if(board[row][i] == num)    return false;
            // checking the entire col
            if(board[i][col] == num)    return false;

            // now check the 3*3 submatrix -> this comes from the 2D array indexing to 1D array.
            if(board[3 * (row/3) + (i/3)][3*(col/3)+(i%3)] == num) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                if(board[row][col] == '.')
                {
                    for(char ch = '1'; ch <= '9'; ch++)
                    {
                        if(isPossible(row,col,ch,board) == true)
                        {
                            board[row][col] = ch;
                            if(solve(board) == true)
                                return true;
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool getAns = solve(board);
    }