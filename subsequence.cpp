#include<iostream>
#include<vector>
using namespace std;

void print(vector<char>v){
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void rec(int i, int n, vector<char>& v, vector<char>& store){

    // base case
    if(i >= n){
        print(store);
        return;
    }

// taking the element.
    store.push_back(v[i]);
    rec(i+1,n,v,store);

// not taking the element.
    store.pop_back();
    rec(i+1,n,v,store);

}

int main()
{
    int n;
    cin>>n;

    vector<char> arr(n);
    vector<char> store;
    // taking input to the array.
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    //printing the subsequence of the array.
    rec(0,n,arr,store);
    
    return 0;
}