#include <iostream>
#include <vector>
using namespace std;

// check out the powerset video of the striver.

// this is the recrusion approach, but we can do this using the bit manipultaion.
void printSequence(string &output, string s, int i)
{
    if (i >= s.length())
    {
        if (output.empty())
            cout << "NULL" << endl;
        else
            cout << output << endl;
        return;
    }

    output.push_back(s[i]);
    printSequence(output, s, i + 1);

    output.pop_back();
    printSequence(output, s, i + 1);
}

// bit manipultaion function of the subsequence.
void printSequence(string output, string s)
{
    // total number of subsequence is -> 2^(n)
    // 2^(n) === (1 << n)
    int n = s.size();
    for (int i = 0; i <= (1 << n) - 1; i++)
    {
        // now iterating for the each number and check if the i-th bit is set or not.
        // if the i-th bit is set then we take that number else not.
        for (int j = 0; j < n; j++)
        {
            // check if the bit is set or not.
            if (i & (1 << j))
            {
                output.push_back(s[j]);
            }
        }
        cout << output << endl;
        output.clear();
    }
}

void generateSubsequence(string str)
{
    // empty string is the output string.
    string output = "";
    // printSequence(output,str,0);
    // new call for the bit manipulation function
    printSequence(output, str);
}

int main()
{
    string str = "abc";
    generateSubsequence(str);
    return 0;
}