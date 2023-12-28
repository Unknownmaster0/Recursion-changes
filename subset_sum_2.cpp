#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// In this question we need to print all the unique subsets of the array. And array may contain the duplicate element.
// problem link -> https://leetcode.com/problems/subsets-ii/submissions/1130297955/

int main()
{
    
    return 0;
}

void solve(vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans, int idx, int n)
{
    if(idx < n)
    {
        ans.push_back(ds);

        for(int i = idx; i<n; i++)
        {
            // if the current element is same as that of previous that we can't choose it for same size.
            if(i > idx && nums[i] == nums[i-1])
                continue;
            ds.push_back(nums[i]);
// run this commented part line to learn the recursion call stack in more detail way and build the recursion tree in your copy.
            // cout<<"ds after push i-> "<<i<<endl;
            // for(auto i:ds)
            //     cout<<i<<" ";
            // cout<<endl;
            solve(nums, ds, ans, i+1, n);
            ds.pop_back();
            // cout<<"ds after pop i-> "<<i<<endl;
            // for(auto i:ds)
            //     cout<<i<<" ";
            // cout<<endl;
        }
    }
    else if(idx == n){
        ans.push_back(ds);
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int>temp;
    solve(nums, temp, ans, 0, nums.size());
    return ans;
}