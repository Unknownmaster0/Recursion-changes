#include <iostream>
#include <vector>
using namespace std;
/* just to modify the program a little bit ->
    we use the boolean function this time.
    and when the first time we satisfy the condition of finding the sum, then we going to return at that time no need to call for the further
    recursion.*/

// don't need the store data structure here. but not deleted due to lazyness .
int printSequence(int s, int n, int *a, int target, int &sum, vector<int> &store)
{
    // base case
    if (s >= n)
    {
        if (sum == target)
        {
            // cout << "the subsequence is -> " << endl;
            // for (auto i : store)
            //     cout << i << " ";
            // cout << endl;
            return 1;
        }
        return 0;
    }

    // take the index (taking)
    // store.push_back(a[s]);
    sum += a[s];
    int left = printSequence(s + 1, n, a, target, sum, store);

    // removing the added index (Not taking)
    // store.pop_back();
    sum -= a[s];
    int right = printSequence(s + 1, n, a, target, sum, store);

    return left + right;
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

    // now no need of data structure to store the sum
    // data structure to store the subsequece.
    vector<int> store;
    int find = 0;
    // int nSubsequence =
    // cout << printSequence(0, n, a, sum, find) << endl;
    int ans = printSequence(0, n, a, sum, find, store);
    cout << "ans -> " << ans << endl;

    // cout<<"the number of subsequence is -> "<<nSubsequence<<endl;

    return 0;
}