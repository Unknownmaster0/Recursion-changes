#include <iostream>
#include <vector>
using namespace std;

void printSequence(int s, int n, int *a, vector<int> &store, int target, int& sum)
{
    // base case
    if (s >= n)
    {
        if (sum == target)
        {
            cout<<"the subsequence is -> "<<endl;
            for (auto i : store)
                cout << i << " ";
            cout << endl;
        }
        return;
    }

    // take the index (taking)
    store.push_back(a[s]);
    sum += a[s];
    printSequence(s + 1, n, a, store, target, sum);
    // removing the added index (Not taking)
    store.pop_back();
    sum -= a[s];
    printSequence(s + 1, n, a, store, target, sum);
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