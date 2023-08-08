#include<iostream>
using namespace std;

// MY APPROACH --> QUITE BIG

// int find_sum(int arr[],int size){
//     // base case 
//     if(size == 0) return 0;

//     // processing 
//     int n = size - 1; // -> this step is because, we not use able to use the size variable for accessing the elements of the array.

//     // recursive relation
//     int sum = find_sum(arr,n); // this relation is stored in the variable as we need this value to iterate the sum;

//     // processing
//     int final_sum = sum + arr[n]; // here the previously sum is added with the next element.

//     return final_sum;
// }

// Quite easy one ___________
// int find_sum(int arr[],int size){
//     // Base case
//     if(size <= 0) return 0;

//     // recursive relation
//     return (find_sum(arr,size-1)+ arr[size-1]) ;
// }

// one more method _________________________________________________
// in this solution, hmlog array ko cut krte ja rhe hai aage se
/*
Example ->   1 2 34 4 5  arr[0] = 1
             2 34 4 5  arr[0] = 2
             34 4 5  arr[0] = 34
             4 5     arr[0] = 4
             5      arr[0] = 5;

             and finally jab size == 1, ho gya then return arr[0];
*/
int find_sum(int arr[],int size){
    // base case
    if(size == 1) return arr[0];

    int remainingPart = find_sum(arr+1,size-1); 
    int sum = arr[0] + remainingPart;// hr baar arr[0] ko add krte jana hai jo pahle se usme. Every time arr[0] wil gets change.

    return sum;
}

int main()
{
    int arr[] = {1,2,3,5,7,8,2,1};
    int size = 8;

    int ans = find_sum(arr,size);
    cout<<"the sum of the elements of the array is -> "<<ans<<endl;

    return 0;
}