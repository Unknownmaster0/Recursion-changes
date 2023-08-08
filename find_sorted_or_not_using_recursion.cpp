/*
Question -> check if the array is sorted or not using recursive function.
*/
#include<iostream>
#include<vector>
using namespace std;

// NICE APPROACH ->>>>>>>>>>
// bool isSorted(int arr[],int size){
//     // Base case
//     if(size == 1 || size == 0)return 1;

//     // processing
//     if(arr[0] > arr[1]) return 0;

//     // recursive relation
//     bool ans = isSorted(arr+1,size-1);
//     return ans;

// }

// thinking something new--------------
bool isSorted(int arr[],int size){

    if(size == 0)return 1;

    int n = size -1 ;
    
    bool ans = isSorted(arr,n);

    bool check = 1; // checking if the below condition is true or not 
    // ek bar function ke andar jane pr n and size ka value different hai. check it. using recursion tree.
    if(arr[n] > arr[size]) check = 0;

    return check & ans;

}


int main()
{
    // vector<int>arr {1,2,3,6,7,8,9};
    int arr[] = {1,2,3,4,5,6,7};
    int size = 7;
    cout<<"1 for true and 0 for false -> "<<isSorted(arr,size);
    return 0;
}