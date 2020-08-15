// https://hack.codingblocks.com/app/contests/1496/250/problem
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int n;
int *arr;

ll solve(int i, string arr1, int sum1, string arr2, int sum2){
    if(i==n){
        if(sum1==sum2){
            cout<<arr1<<"and "<<arr2<<endl;
            return 1; 
        }
        return 0;
    }
    int ans=0;
    ans += solve(i+1, arr1+to_string(arr[i])+" ", sum1+arr[i], arr2, sum2);
    ans += solve(i+1, arr1, sum1, arr2+to_string(arr[i])+" ", sum2+arr[i]);
    return ans;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    arr = new int[n];
    ip(arr,n);
    
    string arr1="", arr2="";
    ll ct = solve(0, arr1, 0, arr2, 0);
    cout<<ct<<endl;
    return 0;
}