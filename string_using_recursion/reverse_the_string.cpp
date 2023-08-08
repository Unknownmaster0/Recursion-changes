#include <iostream>
#include <string>
using namespace std;

// using the loop
// string reverse_string(string arr,int start,int end){
//     while(start < end){
//         swap(arr[start] ,arr[end]);
//         start++;
//         end--;
//     }
//     return arr;
// }

// using recursion of this code
void reverse_string(string &arr, int start, int end)
{
    if (start >= end)
        return;

    swap(arr[start], arr[end]);
    reverse_string(arr, start + 1, end - 1);
}


int main()
{
    string arr = "sagar";
    reverse_string(arr, 0, arr.length() - 1);
    cout << "reverse string is -> " << arr << endl;
    return 0;
}