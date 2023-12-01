#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
// this is also True but the brutforce one 
// having time complextiy -> O(2^t * k * x) [k for the temp] [x for the set to the vector]
// and also used the extra space in form of set.
    void solve(set<vector<int>>& ans, vector<int>temp, vector<int>arr,int target, int idx)
    {
        if(idx >= arr.size())
        {
            if(target == 0)
            {
                // sort(temp.begin(),temp.end());
                // if( find(ans.begin(),ans.end(),temp) == ans.end() )
                ans.insert(temp);
            }
            return;
        }
    
        // pick the element
        if(arr[idx] <= target)
        {
            temp.push_back(arr[idx]);
            solve(ans,temp,arr,target-arr[idx],idx+1);
            temp.pop_back();
        }
        // Not pick element
        solve(ans,temp,arr,target,idx+1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(),candidates.end());
        set<vector<int>> ans;
        vector<int>store;

        solve(ans,store,candidates,target,0);
        vector<vector<int>>result;
        for(auto& it:ans){
            result.push_back(it);
        }
        return result;
    }
*/

void solve( int idx,int target,vector<vector<int>>& ans, vector<int>temp, vector<int>arr)   
{
    // base case
    if(target == 0)
    {
        ans.push_back(temp);
        return;
    }

    for(int i = idx; i<arr.size(); i++)
    {
// just check if the previous element is same as the current element, then don't pick this element.
        if(i > idx && arr[i] == arr[i-1]) continue;

// check if the array element is greater than the target, then no need to iterate the loop, simply break
// as the array is in sorted order and the elements after that are also greater or equal to the current element.
        if(arr[i] > target) break;

// if none of the condition above is true, then pick up this element.
        temp.push_back(arr[i]);
        solve(i+1,target-arr[i],ans,temp,arr);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
// recursive call
    solve(0,target,ans,temp,candidates);
    return ans;
}

int main()
{
    
    return 0;
}