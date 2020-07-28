#include<iostream>
#include<vector>
#include<cstring>
#include<iomanip>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

double dp[105][105][105];

/*

when will rock win
    1. when all paper are zero, so return 1
    2. when either scissor or rock zero rock cant win

when will scissor win
    1. when all rock are zero, so return 1
    2. when either paper or scissor 0, scissor cant win

when will paper win
    1. when all scissor are 0, so return 1
    2. when either rock or paper 0, paper cant win
*/

double solve(ll r, ll s, ll p){
    if(s==0||r==0) return 0.0;
    if(p==0) return 1.0;

    if(dp[r][s][p] > -1) return dp[r][s][p];

    double ans=0;
    double total = (r*s + s*p + p*r);

    // here we have three case and in each case wwe multiply with prop of occuring of the event and call recursion
    ans += (r*p) * solve(r-1, s, p); // fight b/w rock and paper, and paper win so rock-1
    ans += (r*s) * solve(r, s-1, p); // fight b/w rock and scissor, and rock win so scissor-1
    ans += (s*p) * solve(r, s, p-1); // fight b/w scissor and paper, and scissor win so paper-1

    ans /= total;

    return dp[r][s][p] = ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,s,p;
        cin>>r>>s>>p;
        memset(dp, -1, sizeof(dp));
        cout<<fixed<<setprecision(9)<<solve(r, s, p)<<" ";
        memset(dp, -1, sizeof(dp));
        cout<<fixed<<setprecision(9)<<solve(s, p, r)<<" ";
        memset(dp, -1, sizeof(dp));
        cout<<fixed<<setprecision(9)<<solve(p, r, s)<<" ";
        cout<<endl;
    }
    return 0;
}