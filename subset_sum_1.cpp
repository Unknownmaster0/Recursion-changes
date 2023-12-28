#include<iostream>
#include<vector>
using namespace std;

// problem link -> https://practice.geeksforgeeks.org/problems/subset-sums2234/1

void solve(vector<int>&arr, int n, vector<int>&ds, int idx, int sum)
{
    if(idx >= n)
    {
        ds.push_back(sum);
        return ;
    }
    
    // first take the element.
    solve(arr, n, ds, idx+1, sum + arr[idx]);
    
    // not pick up that element.
    solve(arr, n, ds, idx+1, sum);
}

vector<int> subsetSums(vector<int> arr, int N)
{
    vector<int>ds;
    solve(arr,N,ds,0,0);
    return ds;
}

int main()
{
    
    return 0;
}