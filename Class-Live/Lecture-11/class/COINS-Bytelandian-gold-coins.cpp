// Link: https://www.spoj.com/problems/COINS/
//The input will contain several test cases (not more than 10). Each testcase is a single line with a number n, 0 <= n <= 1 000 000 000. It is the number written on your coin.

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10000000
ll dp[MAX];

ll solve(ll n){
    if(n<MAX) return dp[n];
    ll temp = n;
    n = solve(n/2)+solve(n/3)+solve(n/4);
    return max(temp, n);
}

int main(){
    ll n;

    for(int i=0; i<12; i++) dp[i]=i;
    for(ll i=12; i<MAX; i++){
        dp[i] = max(i, dp[i/2]+dp[i/3]+dp[i/4]);
    }
    while(cin>>n){
        cout<<solve(n)<<endl;
    }
    return 0;
}