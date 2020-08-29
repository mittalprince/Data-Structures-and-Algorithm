/*
Indian Premier League (IPL) 2020 will be held across all 3 venues in the United Arab Emirates -- Dubai, Abu Dhabi, and Sharjah from September 19 to November 8.
Indian Premier League tickets are limited so, the Indian Government gives two random numbers a and b to the Dubai Government. Dubai Government wants to give the ticket to all candidates with IDs between a and b ( both inclusive ), However, due to coronavirus pandemic time Government can't give tickets to every candidate, Dubai Government decides to give the ticket to candidates having special ID,
The property of a special ID is as follows:
A special ID is not divisible by any number of the form p*p where (p>1).
So your task is to find the number of candidates getting the tickets.

1<=T<=10
1<= a and b <=10^9
0<= | a -b | <= 10^6

1 
1 10

7
*/

// https://hack.codingblocks.com/app/contests/1783/1736/problem
#include<iostream>
#include<vector>
#include<cstring>
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
#define MAX 1000005

bool vis[MAX];

void solve(){
    ll mi,mx;
    cin>>mi>>mx;
    memset(vis, 1, sizeof(vis));

    for(ll i=2; i*i<=mx; i++){
        ll num = i*i;

        ll start = (mi/num)*num;
        if(start<num) start+=num;

        for(ll j=start; j<=mx; j+=start){
            vis[start-mi]=false;
        }
    }

    ll ans=0;
    for(ll i=0; i<(mx-mi+1); i++){
        ans += vis[i];
    }
    cout<<ans<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}