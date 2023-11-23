#include <iostream>
#include <vector>
using namespace std;
/* just to modify the program a little bit ->
    we use the boolean function this time.
    and when the first time we satisfy the condition of finding the sum, then we going to return at that time no need to call for the further
    recursion.*/

bool printSequence(int s, int n, int *a, vector<int> &store, int target, int &sum)
{
    // base case
    if (s >= n)
    {
        if (sum == target)
        {
            cout << "the subsequence is -> " << endl;
            for (auto i : store)
                cout << i << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // take the index (taking)
    store.push_back(a[s]);
    sum += a[s];
    if (printSequence(s + 1, n, a, store, target, sum) == true)
        return true;
    // removing the added index (Not taking)
    store.pop_back();
    sum -= a[s];
    if (printSequence(s + 1, n, a, store, target, sum) == true)
        return true;

    // else if you don't find the true in both the function call then return false at the end.
    return false;
}

int main()
{
    // n -> size of the array
    int n;
    cin >> n;

    int sum;
    cin >> sum;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // data structure to store the subsequece.
    vector<int> store;
    int find;
    printSequence(0, n, a, store, sum, find);

    return 0;
}