#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsets(string digits,string output,vector<string>&ans,int index,string mapping[]){
    // base case 
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }
    // finding the number stored in the digits
    int number = digits[index] - '0';
    // findign the correct mapping of the string with that number in the phone keypad using mapping string
    string value = mapping[number];

    for(int i = 0; i<value.length(); i++){
        output.push_back(value[i]);
        subsets(digits,output,ans,index+1,mapping);
        output.pop_back();
    }

}


vector<string> letterCombinations(string digits) {
    vector<string>ans; // for returning the ans
    if(digits.length() == 0){
        return ans;
    }
    string output;
    // for the mapping of the number from 2-9 in the phone keypad.
    string mapping[10] = { "", "", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    subsets(digits,output,ans,0,mapping);

    return ans;

}

int main()
{
    string digits = "23";
    vector<string>ans = letterCombinations(digits);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    return 0;
}