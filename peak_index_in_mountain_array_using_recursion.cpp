#include <iostream>
using namespace std;

int peak_index(int a[], int start, int end)
{
    // base case
    if (start <= end)
    {
        // processing
        int mid = (start + end) / 2;

        if (a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
            return mid;

        else if (a[mid] < a[mid + 1] || a[mid] > a[mid - 1])
        {
            start = mid + 1;
            return peak_index(a, start, end);
        }
        else
        {
            end = mid - 1;
            return peak_index(a, start, end);
        }
    }
    return -1;
}

int main()
{
    // int arr[] = {3, 5, 3, 2, 0};
    int arr[] = {0, 2, 1, 0};
    // Please update the size of array if you change the array.
    int size = 4;

    int index = peak_index(arr, 0, size - 1);
    cout << "The peak index is -> " << index << endl;

    return 0;
}