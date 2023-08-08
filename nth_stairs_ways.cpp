/*
Question -> https://www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650
        Find the number of ways to go the nth stairs, if one can jump to 1 or 2 stairs at a time.
*/
#include<iostream>
using namespace std;

int counting_ways(int nth_stairs){
    // base case :
    if(nth_stairs < 0) return 0; // less then 0 wale stairs nhi hote.
    if(nth_stairs == 0) return 1; // 0th stairs se 0th stairs pr aane ka kitna combination ho sakta hai

    // recursive relation
    return counting_ways(nth_stairs-1) + counting_ways(nth_stairs-2); // ya to n-1 stair se aayega or n-2 stair se, nth stair pr.
}

int main()
{
    int stairs;
    cout<<"enter number of stairs-> ";
    cin>>stairs;

    cout<<"The number of ways are -> "<<counting_ways(stairs);

    return 0;
}