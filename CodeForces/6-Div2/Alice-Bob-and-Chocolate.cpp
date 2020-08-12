// https://codeforces.com/contest/6/problem/C
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

void solve(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);

    if(n==1){
        cout<<"1 0\n";
        return;
    }

    int l=0, r=n-1;
    int a=arr[l++], b=arr[r--];
    int ct_a=1, ct_b=1;

    while(l<=r){
        if(a<=b){
            a += arr[l++];
            ct_a++;
        }
        else{
            b += arr[r--];
            ct_b++;
        }
    } 
    cout<<ct_a<<" "<<ct_b<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}