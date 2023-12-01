/*
We are just splitting array into two parts continuosly,till when we not get the one element in the array.
Then after splitting it to the one element left in the array, we started to merging the array by sorting technique.

Merge sort by dynamically allocating the new array

*/
#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int start,int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// this is also the way how we do the merge sort. 
// **** More easier way to merge. *******
void merge(vector<int>&arr, int low, int mid, int high)
{
    
    // first array is from low to mid and the second array is from mid +1 to high
    vector<int> temp;
    
    int i = low, j = mid +1;
    while(i <= mid && j <=high)
    {
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
            
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i <= mid)
        temp.push_back(arr[i++]);
        
    while(j <= high)
        temp.push_back(arr[j++]);
        
        
    int k = 0;
    for(int i = low; i<=high; i++)
        arr[i] = temp[k++];
    
    return;
}


// In this we merging the two sorted array.
void merge(int arr[], int start, int end)
{
// This is for understanding the flow of the merge sort.
    // printArray(arr,start,end);
    // cout<<"start -> "<<start<<endl;
    // cout<<"end -> "<<end<<endl;
    // cout<<"*********************************"<<endl;

    int mid = start + (end - start) / 2;

    // creating two new array
    int size_of_first = mid - start + 1;
    int size_of_second = end - mid;

    int *first = new int[size_of_first];   // created the first array dynamically
    int *second = new int[size_of_second]; // created the second array dynamically

    // copying the elments in the first array from the main array
    int main_array_index = start;
    for (int i = 0; i < size_of_first; i++)
        first[i] = arr[main_array_index++];

    // copying the elments in the second array from the main array
    main_array_index = mid + 1;
    for (int i = 0; i < size_of_second; i++)
        second[i] = arr[main_array_index++];

    // Now as both array are sorted, then start merging it into sorted order.
    int first_index = 0;
    int second_index = 0;
    int arr_index = start; // all these three are the starting index of the respective array.

    // iterating the loop
    while (first_index < size_of_first && second_index < size_of_second)
    {

        if (first[first_index] < second[second_index])
            arr[arr_index++] = first[first_index++];
        else
            arr[arr_index++] = second[second_index++];
    }

    // After merging both the array if any array size is greater then other, then some of the elments in the larger array will left. So, filling the elements of the larger array in the main array
    // if the first array is larger in length then second
    while (first_index < size_of_first)
    {
        arr[arr_index++] = first[first_index++];
    }
    // if the second array is larger in length then first
    while (second_index < size_of_second)
    {
        arr[arr_index++] = second[second_index++];
    }

    // deallocating the allocated memory of the array.
    delete[] first;
    delete[] second;
}

// In this function we sorted the array by splitting it into single element.
void merge_sort(int arr[], int start, int end)
{
    // base case -> kab tk torte rhna hai array ko, when it left with one element only
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    // split the left part  then end -> mid
    merge_sort(arr, start, mid);

    // split the right part then start -> mid + 1;
    merge_sort(arr, mid + 1, end);

    // now start to merge the splitted array in sorted order.
    merge(arr, start, end);
}

int main()
{
    int arr[] = {2, 6, 23, 7, 2, 4, 7};
    int size = 7;

    merge_sort(arr, 0, size - 1);
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    // printArray(arr, size);

    return 0;
}