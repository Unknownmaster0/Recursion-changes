/*
It is same as the permutation problem we solved in the class 12th.
Input -> "abc" find all the permutations of this string.

    Ans ->  {"abc","acb","bac","bca","cab","cba"}  (3! = 6)
    we know as the string contains the "n" letters then the permutations will be n!(n factorial);

Concept -> we have to use the recursion and give all the letter the chance to go on particular position.
            We solve only the one step and rest will be done by the recursion.

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

/*The time complexity of both the function solve and permutations are same -> ***O(n! * n)*****/
/*But the space complexity is optimised in the permutations function as we are not using some freq array to mark if the particular idx is visited or not.*/

// same approach but using extra space complexity -> O(n!) + O(n) + O(n) [the last O(N) space is extra as it is not be there in permutation one.]
/*
void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>ds, vector<int> &freq)
{
    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<freq.size(); i++)
    {
        if(freq[i] == 0)
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            solve(nums,ans,ds, freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
*/

void permutations(string str,vector<string>& ans, int index){

    // base case
    if(index >= str.length()){
        ans.push_back(str);
        return;
    }

    for(int i = index; i<str.length(); i++){
        swap(str[i],str[index]);
        permutations(str,ans,index+1);
        // backtracking step
        swap(str[i],str[index]); // revert the changes
    }

}

vector<string> lettercombinations(string& str){

    vector<string>ans;
    permutations(str,ans,0);

    sort(ans.begin(),ans.end());

    return ans;
}

int main()
{
    string str = "abc";
    vector<string>ans = lettercombinations(str);

    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}