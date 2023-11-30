#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/generate-parentheses/submissions/1109375630/

//  concept -> ********************* below function.

//     void solve(vector<string>& ans, string output, int o, int c)
//     {
//         // base case
//         if(o == 0 && c == 0)
//         {
//             ans.push_back(output);
//             return;
//         }

// // if open bracket and closing bracket count are same then we can only apply
// // the opening braket
//         if(o == c)
//         {
//             solve(ans, output+'(',o-1,c);
//         }

// // if open bracket count is 0 then only option to add closing bracket.
//         else if(o == 0)
//             solve(ans, output+')', o,c-1);

// // if closing bracket count is 0 then only option to add opening bracket.
//         else if(c == 0)
//             solve(ans, output+'(',o-1,c);

// // else if both are not zero and none are equal
//         else{
//             solve(ans,output+'(',o-1,c);
//             solve(ans,output+')',o,c-1);
//         }
//     }

// this can be the gist of the above code.
void solve(vector<string> &ans, string output, int o, int c,int n)
{
    if(output.size() == 2 * n)
    {
        ans.push_back(output);
        return;
    }

    if(o > 0)
        solve(ans, output+'(',o-1,c,n);

    if(c > o)
        solve(ans,output+')',o,c-1,n);
}

vector<string> validParenthesis(int n){
    vector<string> ans;
    // o = open bracket
    // c = close bracket
    int o = n, c = n;
    solve(ans,"",o,c,n);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<string> ans = validParenthesis(n);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}