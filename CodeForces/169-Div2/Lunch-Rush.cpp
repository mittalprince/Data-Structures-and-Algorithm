// https://codeforces.com/contest/276/problem/A
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int f,t;
    int mx=0;
    cin>>f>>t;
    if(t>k) mx = f-(t-k);
    else mx = f;
    for(int i=1; i<n; i++){
        cin>>f>>t;
        if(t>k) mx = max(mx, f-(t-k));
        else mx = max(mx, f);
    }
    cout<<mx<<endl;
    return 0;
}