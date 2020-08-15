// https://hack.codingblocks.com/app/contests/1496/131/problem
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
int sum=0;

int solve(int i, int s, string ans){
    if(i==n){
        if(s==sum){
            cout<<ans<<" ";
            return 1;
        }
        return 0;
    }

    ll ways=0;
    ways += solve(i+1, s+arr[i], ans+to_string(arr[i])+" ");
    ways += solve(i+1, s, ans);
    return ways;
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    arr = new int[n];
    ip(arr, n);
    cin>>sum;
    int ways = solve(0, 0, "");
    cout<<endl<<ways<<endl;
    return 0;
}