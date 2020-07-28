// https://codeforces.com/problemset/problem/296/c
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
#define MAX 100005

/*
Logic Used: Prefic Sum

First we find how many time ith operation repeat by using prefix sum logic
Then we check what val will be changed by performing ith operation ct[i] times

Then add this diff into arr[i]
*/

ll diff[MAX]={0}, ct[MAX]={0}, arr[MAX]={0}, l[MAX], r[MAX], d[MAX];
ll n,m,k;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>k;
    ip1(arr, n);

    for(ll i=1; i<=m; i++){
        cin>>l[i]>>r[i]>>d[i];
    } 

    for(ll i=0; i<k; i++){
        ll x,y;
        cin>>x>>y;
        ct[x]++;
        ct[y+1]--;
    }

    for(ll i=1; i<=m; i++){
        ct[i] += ct[i-1];
    }

    for(ll i=1; i<=m; i++){
        diff[l[i]] += ct[i]*d[i];
        diff[r[i]+1] -= ct[i]*d[i];
    }

    for(ll i=1; i<=n; i++){
        diff[i] += diff[i-1];
        arr[i] += diff[i];
    }

    for(ll i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}