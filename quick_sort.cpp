/*
Quick sort -> Two step process
            step 1-> first do the partition for the first element, and first element as pivot.
            step 2-> check that element in the left part of the pivot should be less than pivot
                    and element in right part must be greater then pivot.

            we have do one case and other will be done by the recursive call.

Quick sort is in place algorithm = it means that it doesn't make any copy of the given array and instead implement the algorithm on the same.
                                    This makes quick sort to save the memory of the heap.
*/
#include <iostream>
#include <vector>
using namespace std;

void display(int* arr,int start,int end){
    for(; start<= end; start++){
        cout<<arr[start]<<" ";
    }cout<<endl;
}

// this function is for finding the pivot Index.
int findPivot(vector<int>&arr, int low, int high)
{
    int pivot = arr[low];
    int left = low, right = high;
    
    while(left < right)
    {
        while(left <= high && arr[left] <= pivot )
            left++;
            
        while(right >= low && arr[right] > pivot)
            right --;
            
        if(left < right)
            swap(arr[left],arr[right]);
    }
    
    swap(arr[low],arr[right]);
    
    cout<<"low -> "<<low<<" highh -> "<<high<<endl;
    for(int i = low; i<=high; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return right;
}

int partition(int *arr, int start, int end)
{
    cout<<"in partition check"<<endl;
    display(arr,start,end);
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (pivot >= arr[i])
            count++;
    }

    int pivotIndex = start + count;
    cout<<"pivotIndex-> "<<pivotIndex<<endl;

    // making the partition by placing the pivot in its original position
    swap(arr[start], arr[pivotIndex]);

    // Now after partition we need to confirm that elements in the left of the pivot must be smaller and the elements in the right of the pivot must be greater
    // we need to iterate the loop till the start < pivotIndex and end > pivotIndex
    while (start < pivotIndex && end > pivotIndex)
    {
        if (arr[start] <= pivot)
        {
            start++;
        }
        else if (arr[end] > pivot)
        {
            end--;
        }
        // this will need to think of one more condition which is not neccessary --->
        // else if (arr[start] > pivot && arr[end] <= pivot)
        // {
        //     swap(arr[start++], arr[end--]);
        // }
        else{
            swap(arr[start++], arr[end--]);
        }
    }

    return (pivotIndex);
}

void quick_sort(int *arr, int start, int end)
{

    cout<<"in quick_sort check"<<endl;
    display(arr,start,end);
    // base case
    if (start >= end)
        return;

    // processing -> do the first partition
    int index = partition(arr, start, end);

    // calling quick sort for the left part
    quick_sort(arr, start, index - 1);

    // calling quick sort for the right part
    quick_sort(arr, index + 1, end);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {5,3,2,3,5};
    int size = 5;

    quick_sort(arr, 0, size - 1);
    printArray(arr, size);

    return 0;
}
