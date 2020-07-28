#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

char phone[][10] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> searchIn = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void findStrings(string s, int i, string out){
    if(i==s.length()){
        for(string str: searchIn){
            if(str.find(out) != str.npos){
                // ans.insert(str);
                cout<<str<<endl;
            }
        }
    }
    int idx = s[i]-'0';
    for(int k=0; k<strlen(phone[idx]); k++){
        out += phone[idx][k];
        findStrings(s, i+1, out);
        out.pop_back();
    }
}
int main(){
    string input;
    cin>>input;
    findStrings(input, 0, "");
    return 0;
}