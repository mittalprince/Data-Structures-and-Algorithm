// https://codeforces.com/contest/1399/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
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

int getCount(vector<int>&arr, int n, int sum){
    int i=0, j=n-1;
    int ans=0;
    while(i<j){
        if(arr[i]+arr[j]==sum){
            ans++;  i++; j--;
        }
        else if(arr[i]+arr[j]>sum)j--;
        else i++;
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);

    sort(arr.begin(), arr.end());
    int ans=0;
    for(int i=2; i<=2*n; i++){
        ans = max(ans, getCount(arr, n, i));
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