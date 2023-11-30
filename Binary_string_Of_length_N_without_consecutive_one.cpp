#include<iostream>
#include<vector>
using namespace std;
// question link -> https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?leftPanelTabValue=SUBMISSION
/*Question -> print all the binary strings of length N, such that no strings should contains any consecutive 1's in their digit.*/

// recursive function to generate all the strings.
void solve(int N, vector<string>& ans, string output, int index)
{
  if (index == N) {
    ans.push_back(output);
    return;
  }

  // add 0 to the output string.
  solve(N, ans, output+'0', index+1);

  // add 1 to the output string if the just previous index is not 1.
  if(index == 0 || (index > 0 && output[index-1] != '1'))
    solve(N, ans, output+'1', index + 1);

}
vector<string> generateString(int N) {
    
// approach -> we are using the recursion to print all the binary string of length N
// so,******** the time complexity will -> exponential[2^N] ************* 
//  but can be optimised by using the DP.As the constraints are low, so, we can use the normal recursion technique.

    vector<string> ans;
// we are sending the output string which is initially blank, and initial index as 0.
    solve(N,ans,"",0);
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<string> ans = generateString(n);
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}