#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll findWays(ll arr[], int n, int i, string arr1, int sum1, string arr2, int sum2){
    if(i == n){
        if(sum1 == sum2){
            cout<<arr1<<"and "<<arr2<<endl;
            return 1; 
        }
        return 0;
    }

    int ct=0;
    ct += findWays(arr, n, i+1, arr1+to_string(arr[i])+" ", sum1+arr[i], arr2, sum2);
    ct += findWays(arr, n, i+1, arr1, sum1, arr2+to_string(arr[i])+" ", sum2+arr[i]);
    return ct;
}
int main(){
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    string arr1="", arr2="";
    ll ct = findWays(arr, n, 0, arr1, 0, arr2, 0);
    cout<<ct<<endl;
    return 0;
}