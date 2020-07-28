//Problem Link:

/*
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.

*/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool checkValidString(string s){
    int left=0, right=0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '*') left++;
        else left--;

        if(left<0) return false;
    }

    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == ')' || s[i] == '*') right++;
        else right--;

        if(right<0) return false;
    }
    return true;
}
int main(){
    string s;
    cin>>s;

    return 0;
}