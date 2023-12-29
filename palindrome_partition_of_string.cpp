#include<iostream>
#include<vector>
using namespace std;

int main()
{
    
    return 0;
}

    bool isPossible(int start, int end, string&str)
    {
        while(start <= end)
        {
            if(str[start++] != str[end--])  return false;
        }
        return true;
    }

    void solve(string& s, vector<vector<string>>& ans, vector<string>&temp, int idx)
    {
        if(idx == s.size())
        {
            ans.push_back(temp);
            return;
        }

// trying out the partition at every index of the string s.
        for(int i = idx; i<s.size(); i++)
        {
            // check if it possible to give partition at that idx.
            if(isPossible(idx,i,s))
            {
                temp.push_back(s.substr(idx,i-idx+1));
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        // to generate all the palindrome partitioning string, we have to do partition at every index.
        vector<vector<string>> ans;
        vector<string>temp;
        solve(s,ans,temp,0);
        return ans;
    }