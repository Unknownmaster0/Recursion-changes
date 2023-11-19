#include<iostream>
#include<algorithm>
#include <math.h>
#include <limits.h>
using namespace std;

int convertInteger(string s)
{
    const int sign = s[0] == '-' ? -1 : 1;
    if (s[0] == '+' || s[0] == '-')
        s = s.substr(1);

    long long ans = 0;
    for(int i = 0 ;i<s.length(); i++)
    {
        if(!isdigit(s[i]))
            break;
        ans = ans * 10 + (s[i] - '0');
        if(sign * ans < INT_MIN)
            return INT_MIN;
        if(sign * ans > INT_MAX)
            return INT_MAX;
    }

    return sign * ans;
}
int createAtoi(string s) {

    // remove the first spaces till not get any digit.
    int i = 0; 
    while(i < s.length())
    {
        if(s[i] == ' '){
            s.erase(i,1);
            continue;
        }
        else if(s[i] != ' ')
            break;
        else 
            i++;
    }

    if(s.empty()){
        return 0;
    }
    return convertInteger(s);
}

int main()
{
    string str = "-91283472332";
    cout<<createAtoi(str)<<endl;
    return 0;
}