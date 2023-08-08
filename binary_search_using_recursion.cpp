#include <iostream>
using namespace std;

bool binary_search(int arr[], int start, int end, int key)
{
    // base case
    if (start > end)
        return 0;
    // processing
    int mid = (start + end) / 2;

    if (arr[mid] < key)
    {
        start = mid + 1;
        binary_search(arr, start, end, key);
    }
    else if (arr[mid] > key)
    {
        end = mid - 1;
        binary_search(arr, start, end, key);
    }
    else
        return 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = 9;
    int key = 1;

    bool ans = binary_search(arr, 0, size - 1, key);
    if (ans)
        cout << "element is present." << endl;
    else
        cout << "element is not present." << endl;
    return 0;
}