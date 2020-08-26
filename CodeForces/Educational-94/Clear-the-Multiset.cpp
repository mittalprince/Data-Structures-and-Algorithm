// https://codeforces.com/contest/1400/problem/E
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
#define MAX (int)5e3+1

vector<vector<int>> minPos; // find min element pos in range [i,j];
ll dp[MAX][MAX];
vector<ll>arr;

ll solve(int from, int to, int curr){
    if(from>to)return 0;

    if(dp[from][to] != -1)return dp[from][to];
    ll idx=from;
    for(int i=from; i<=to; i++){
        if(arr[i]<arr[idx]){
            idx=i;
        }
    }
    int val = arr[idx]; // min element in range [from, to];

    ll opt1 = to-from+1; // choose 2 operation and remove one type of element one by one
    ll opt2 = val-curr; // find diff from prev min and curr min element of arr

    opt2 += solve(from, idx-1, val) + solve(idx+1, to, val);

    return dp[from][to] = min(opt1, opt2);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    arr = vector<ll>(n);
    ip(arr, n);


    memset(dp, -1, sizeof(dp));
    cout<<solve(0, n-1, 0)<<endl;

    return 0;
}