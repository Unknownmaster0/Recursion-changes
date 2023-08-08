#include <iostream>
using namespace std;

// b -> base , p-> power
long long power_calculation(int b,int p){
    // base case
    if(p == 0) return 1;
    if(p == 1) return b;

    // recursive relation 
    int ans = power_calculation(b,p>>1);
    // p is odd
    if(p & 1){
        // here ans = b^p/2;
        return  b * ans * ans;
    }
    else{
        return ans*ans;
    }

}    

int main()
{
    int base, power;
    cout << "enter base-> ";
    cin >> base;
    cout << "enter power-> ";
    cin>>power;

    long long ans = power_calculation(base,power);
    cout<<"Ans -> "<<ans<<endl;
    return 0;
}