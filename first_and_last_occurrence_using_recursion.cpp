#include <iostream>
using namespace std;

int first_occurrence(int a[], int start, int end, int key)
{

    // base case
    if (start <= end)
    {

        // processing
        int mid = (start + end) / 2;

        if (a[mid] == key && a[mid] > a[mid - 1])
        {
            return mid;
        }
        else if (a[mid] >= key)
        {
            end = mid - 1;
            return first_occurrence(a, start, end, key);
        }
        else
        {
            start = mid + 1;
            return first_occurrence(a, start, end, key);
        }
    }

    return -1;
}

int last_occurrence(int a[], int start, int end, int key)
{
    // base case
    if (start <= end)
    {

        // processing
        int mid = (start + end) / 2;

        if (a[mid] == key && a[mid + 1] > a[mid])
            return mid;
        else if (a[mid] <= key)
        {
            start = mid + 1;
            return last_occurrence(a, start, end, key);
        }
        else
        {
            end = mid - 1;
            return last_occurrence(a, start, end, key);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 3, 3, 3, 3, 3, 4};
    int size = 8;

    int first = first_occurrence(arr, 0, size - 1, 3);
    cout << "first occurrence is -> " << first << endl;
    int last = last_occurrence(arr, 0, size - 1, 3);
    cout << "last occurrence is -> " << last << endl;
    return 0;
}