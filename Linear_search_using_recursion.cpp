#include <iostream>
using namespace std;

// METHOD 1.-----------------------------------------
bool find_element(int arr[], int size, int key)
{
    // base case
    if (size == 0)
    {
        return 0;
        exit(0);
    }
    if (arr[0] == key)
    {
        return 1;
    }
    else
    {
        find_element(arr + 1, size - 1, key);
    }
}

// METHOD 2 ----------------------------
// bool find_element(int arr[], int size, int key)
// {
//     // base case
//     if (size == 0)
//         return 0;

// // processing
//     bool check = (arr[0] == key);

// // recursive relation
//     bool search = find_element(arr + 1, size - 1, key);

// // processing
//     return (check || search); // ek bar bhi check agar true hai then ye true ho jayega.
// }

int main()
{
    int arr[] = {1, 2, 45, 6, 88, 4};
    int size = 6;

    int key = 4;

    bool ans = find_element(arr, size, key);
    if (ans)
    {
        cout << "element is found." << endl;
    }
    else
    {
        cout << "element is not present." << endl;
    }
    return 0;
}