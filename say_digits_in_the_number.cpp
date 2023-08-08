/*
Question -> Say the digits in the number one-by-one.
            Example -> 231
            output -> two three one
*/
#include<iostream>
using namespace std;

//  ****MY WAY OF DOING*******
// void say(int num){
//     // Base case
//     if(num == 0)return;

//     // Recursive relation
//     say(num/10);

//     switch (num % 10)
//     {
//     case 1: cout<<"one"<<" ";
//         break;
//     case 2: cout<<"two"<<" ";
//         break;
//     case 3: cout<<"three"<<" ";
//         break;
//     case 4: cout<<"four"<<" ";
//         break;
//     case 5: cout<<"five"<<" ";
//         break;
//     case 6: cout<<"six"<<" ";
//         break;
//     case 7: cout<<"seven"<<" ";
//         break;
//     case 8: cout<<"eight"<<" ";
//         break;
//     case 9: cout<<"nine"<<" ";
//         break;
//     case 0: cout<<"zero"<<" ";
//         break;
    
//     }
// }

// int main()
// {
//     int num;
//     cout<<"enter the number-> ";
//     cin>>num;

//     say(num);

//     return 0;
// }


// ******* Some new way ********
void say(int num,string arr[]){
    // Base case
    if(num == 0) return;

    // obtaining digit
    int digit = num % 10;
    say(num/10,arr);// updating the num

    cout<<arr[digit]<<" ";
}


int main()
{
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int num;
    cout<<"enter the number -> ";
    cin>>num;

    say(num,arr);
    
    return 0;
}
