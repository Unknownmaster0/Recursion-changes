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