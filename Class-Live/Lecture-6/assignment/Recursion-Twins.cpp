#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void counttwins(string s, int i, int &ct){
    if(i > s.length()-2) return;

    if(s[i] == s[i+2] && s[i] != s[i+1]) ct++;
    counttwins(s, i+1, ct);
}

int main(){
    string s;
    cin>>s;
    int ct=0;
    counttwins(s, 0, ct);
    cout<<ct<<endl;
    return 0;
}