#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

int main()
{
    
    return 0;
}

    void solve(vector<string>&store, string path,vector<vector<int>>&visited,
                vector<vector<int>> &m,int n, int row, int col)
    {
        if(row == n-1 && col == n-1){
            store.push_back(path);
            return ;
        }
            
        // check down
        if(row+1 < n && visited[row+1][col] != 1 && m[row+1][col] != 0)
        {
            // go down
            visited[row+1][col] = 1;
            solve(store, path+'D',visited, m, n, row+1, col);
            visited[row+1][col] = 0;
        }
        // check left
        if(col - 1 >= 0 && visited[row][col-1] != 1 && m[row][col-1] != 0)
        {
            // go left
            visited[row][col-1] = 1;
            solve(store, path+'L',visited, m, n, row, col-1);
            visited[row][col-1] = 0;
        }
        // check right
        if(col + 1 < n && visited[row][col+1] != 1 && m[row][col+1] != 0)
        {
            // go right
            visited[row][col+1] = 1;
            solve(store, path+'R',visited, m, n, row, col+1);
            visited[row][col+1] = 0;
        }
        // check up
        if(row-1 >= 0 && visited[row-1][col] != 1 && m[row-1][col] != 0)
        {
            // go up
            visited[row-1][col] = 1;
            solve(store, path+'U',visited, m, n, row-1, col);
            visited[row-1][col] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        if(m[0][0] == 0) return {"-1"};
        vector<string>store;
        vector<vector<int>> visited(n, vector<int>(n,0));
        visited[0][0]=1;
        string path = "";
        solve(store,path,visited, m,n, 0, 0);
        return store;
    }