#include<iostream>
using namespace std;

// understanding link -> https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/

/*
Brutforce method -> iterate two for loop and initialise a varible inv_count = 0; 
                    Whenever you get a[i] > a[j] then inv_count++;
                    finally return inv_count;
                    for(i= 0; i<size; i++){
                        for(j = 1; j<size; j++){
                            if(a[i] > a[j]){
                                inv_count++;
                            }
                        }
                    }
                    return inv_count;
                    ex -> 2 5 1 7 3
                    concept -> traversing array and ,
                                find the number of smaller 
                                elements on its right side of the array. 
                                for each bigger element count++;


*/

int merging(int* arr,int* temp,int start,int mid,int end){
    
    int inv_count = 0;
    int index1 = start,index2 = mid+1;
    int temp_index = start;
    while(index1 <= mid && index2 <= end){
        if(arr[index1] <= arr[index2]){
            temp[temp_index++] = arr[index1++];
        }
        else{
            temp[temp_index++] = arr[index2++];
            
            //IMPORTANT STEP ----->  update the inv_count in this case by (mid+1-index1)  
            inv_count += (mid + 1)-index1;
        }
    }
    
    return inv_count;
}

int merge_sort(int*arr,int* temp, int start,int end){
    int inv_count = 0;
    if(start < end){
        int mid = start + (end - start)/2;
        
        // sorting the left part
        inv_count += merge_sort(arr,temp,start,mid);
        //sorting the right part
        inv_count += merge_sort(arr,temp,mid+1,end);
        
        // merging the sorted array
        inv_count += merging(arr,temp,start,mid,end); // here we share the mid only not mid+1;
    }

    return inv_count;
}

int call_merge_sort(int* arr, int size){
    int temp[size];
    return merge_sort(arr,temp,0,size-1);
}

int main(){
    int arr[] = {1, 20, 6, 4, 5};
    int size = 5;
    
    int count_inversion = call_merge_sort(arr,size);
    cout<<"The total number of inversion is -> "<<count_inversion<<endl;
    for(int i = 0; i<size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}