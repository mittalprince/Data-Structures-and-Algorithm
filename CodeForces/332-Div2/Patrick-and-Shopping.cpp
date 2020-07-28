// https://codeforces.com/contest/599/problem/A
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int a,b,c;
    cin>>a>>b>>c;
    ll opt1 = 2*a + 2*b;
    ll opt2 = a+b+c;
    ll opt3 = 2*c+2*a;
    ll opt4 = 2*c+2*b;

    cout<<min(opt1, min(opt2, min(opt3, opt4)));
    return 0;
}