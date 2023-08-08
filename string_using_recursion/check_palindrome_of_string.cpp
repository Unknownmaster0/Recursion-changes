#include <iostream>
using namespace std;

bool check_palindrome(string str, int i)
{
    if (i > (str.length() - 1 - i))
        return 1;
    if (str[i] != str[str.length() - 1 - i])
        return 0;
    else
    {
        return check_palindrome(str, i + 1);
    }
}

int main()
{
    string str = "aabbccbbaa";
    int ans = check_palindrome(str, 0);
    if (ans)
        cout << "Yes Palindrome" << endl;
    else
        cout << "Not a palindrome" << endl;
    return 0;
}