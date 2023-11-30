#include <iostream>
#include <vector>
using namespace std;

bool solve(int n, int k, vector<int> &a, int sum, int index)
{
    // this condition will being TLE but Why I don't know.
    // if(index == n)
    // {
    //     if(sum == k)
    //         return true;

    //     return false;
    // }

    if (sum == k)
        return true;

    if (sum > k || index >= n)
        return false;

    // take the element.
    sum += a[index];
    if (solve(n, k, a, sum, index + 1) == true)
        return true;

    // not take the element.
    sum -= a[index];
    if (solve(n, k, a, sum, index + 1) == true)
        return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return solve(n, k, a, 0, 0);
}

int main()
{

    return 0;
}