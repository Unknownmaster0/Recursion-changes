/*
In selection sort -> we just placing the ith smallest element in the ith iteration.
                    We do the first case for placing the 1st smallest element and rest will be done by the recursion.
*/
#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    // base case
    if (size == 0)
        return;

    // processing or solving the first case -
    int minIndex = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    if (minIndex)
    {
        swap(arr[0], arr[minIndex]);
    }

    selection_sort(arr + 1, size - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 3, 5, 1, 5, 7, 2};
    int size = 7;

    selection_sort(arr, size);
    printArray(arr, size);

    return 0;
}