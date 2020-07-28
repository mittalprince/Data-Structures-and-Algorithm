// https://codeforces.com/contest/975/problem/C
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

    int n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0)arr[i] += arr[i-1];
    }
    ll total_time=0;
    for(int i=0; i<q; i++){
        ll x;
        cin>>x;
        total_time+=x;
        if(total_time>=arr[n-1]){
            cout<<n<<endl;
            total_time=0;
            continue;
        }
        int s=0, e=n-1, ans;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(arr[mid]>=total_time){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        if(arr[ans] == total_time){
            cout<<n-(ans+1)<<endl;
        }
        else{
            cout<<n-ans<<endl;
        }
    }
    return 0;
}