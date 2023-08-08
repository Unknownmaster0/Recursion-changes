/*
    What we are doing in the bubble sort -> just placing the i-th largest element at the correct place in the ith iteration.
    So, in recursion we just solve the one case, and the rest will be solved by the recusion itself.
    i.e. we have to place the 1st largest element in the right place and the rest will be placed by the recursion itself.
*/

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    // base case
    if (size == 0 || size == 1) // array is already sorted then
        return;                 // don't need to do anything.

    // solving one case
    int swapped = 0;
    int i = 0;
    for (; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = 1;
        }
    }

    if (swapped == 0)
    {   
        return;
    }
    else
    {
        bubble_sort(arr, size - 1);
    }
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
    int arr[] = {2, 5, 1, 6, 8, 4};
    int size = 6;
    bubble_sort(arr, size);
    printArray(arr, size);

    return 0;
}