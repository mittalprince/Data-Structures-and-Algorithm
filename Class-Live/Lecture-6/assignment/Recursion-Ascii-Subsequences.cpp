#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void printSubsequences(string input, string output, int i, int &ct){
    if(i == input.length()){
        cout<<output<<" ";
        ct++;
        return;
    }
    printSubsequences(input, output, i+1, ct);
    output += input[i];
    printSubsequences(input, output, i+1, ct);
    output.pop_back();
    // int no = (int)input[i];
    output += to_string((int)input[i]);
    printSubsequences(input, output, i + 1, ct);
}

int main(){
    string s, output;
    cin>>s;
    int ct=0;
    printSubsequences(s, output, 0, ct);
    cout<<endl<<ct<<endl;
    return 0;
}