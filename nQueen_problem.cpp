#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}


bool isSafe(int col, int row, vector<string>&temp)
{
    int c = col, r = row;
    // check the left row
    while(c >= 0)
    {
        if(temp[r][c] == 'Q') return false;
        c--;
    }

    // check the upper left diagonal.
    c = col, r = row;
    while(c >= 0 && r >= 0)
    {
        if(temp[r][c] == 'Q')   return false;
        r--; c--;
    }

    // check the lower left diagonal
    c = col, r = row;
    while(c >= 0 && r < temp.size())
    {
        if(temp[r][c] == 'Q')   return false;
        r++; c--;
    }

    return true;
}

// Brutforce -> because here we are going and traversing each time for the [left row, upper left diagonal, lower left diagonal]. can be optimised when we use hashmap to keep track of the [leftrow, upper left diagonal, lower left diagonal].
void solve(int col, vector<string>&temp, vector<vector<string>>& ans)
{
    if(col == temp.size())
    {
        ans.push_back(temp);
        return;
    }

    for(int row = 0; row<temp.size(); row++)
    {
        // check if it is safe to put at this row or not.
        if(isSafe(col,row,temp))
        {
            temp[row][col] = 'Q';
            solve(col+1, temp, ans);
            temp[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp(n);
    string str(n,'.');

    for(int i = 0; i<n; i++)
        temp[i] = str;
    solve(0,temp,ans);
    return ans;
}

/************************* optimal approach -> just by modifying a little bit. ******************************/
    void solve(int col, int n,vector<string>&temp, vector<vector<string>>& ans,vector<int>&hashrow,vector<int>&lowerDiagonal,vector<int>&upperDiagonal)
    {
        if(col == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int row = 0; row<n; row++)
        {
            // check if it is safe to put at this row or not.
            // if(isSafe(col,row,temp))
            if(hashrow[row] == 0 && lowerDiagonal[row+col] == 0 && upperDiagonal[ n-1 + col - row] == 0)
            {
                temp[row][col] = 'Q';
                hashrow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1 + col - row] = 1;
                solve(col+1,n, temp, ans, hashrow, lowerDiagonal, upperDiagonal);
                temp[row][col] = '.';
                hashrow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n);
        string str(n,'.');

        for(int i = 0; i<n; i++)
            temp[i] = str;

        // Now we need to make some hasmap to access that.
        vector<int>hashrow(n+1,0);
        vector<int>lowerDiagonal(2*n, 0);
        vector<int>upperDiagonal(2*n, 0);

        solve(0,n,temp,ans,hashrow,lowerDiagonal,upperDiagonal);
        return ans;
    }