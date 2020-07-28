//https://codeforces.com/contest/302/problem/B
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        int c,t;
        cin>>c>>t;
        arr[i] = c*t;
        if(i>0) arr[i] += arr[i-1];
    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        int s=0, e=n-1;
        int ans;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>=x){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}