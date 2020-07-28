// https://codeforces.com/contest/439/problem/A
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n, t;
    cin>>n>>t;
    vector<int> arr(n);
    int sum=0;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        sum += x;
    }
    sum += 10*(n-1);
    if(sum>t){
        cout<<"-1\n";
    }
    else{
        sum -= 10*(n-1);
        int ans = (t-sum)/5;
        cout<<ans<<endl;
    }
    return 0;
}