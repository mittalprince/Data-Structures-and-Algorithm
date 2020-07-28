#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string reformat(string s){
    int digit=0, chars=0;
    string dig="", ch="";
    for(int i=0; i<s.length(); i++){
        if(s[i] >='0' && s[i]<= '9'){
            dig += s[i];
            digit++;
        }
        else{
            ch += s[i];
            chars++;
        }
    }

    if(abs(digit-chars) > 1) return "";
    if(digit > chars){
        dig.swap(ch);
    }

    string ans="";
    for(int i=0; i<s.length(); i++){
        if(i&1){
            ans.push_back(dig[i/2]);
        }
        else{
            ans.push_back(ch[i / 2]);
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;

    return 0;
}