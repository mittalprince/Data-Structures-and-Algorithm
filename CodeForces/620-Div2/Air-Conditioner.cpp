// https://codeforces.com/contest/1304/problem/C
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
    ll n,m;
    cin>>n>>m;
    ll time[n], low_temp[n], high_temp[n];
    for(int i=0; i<n; i++){
        cin>>time[i]>>low_temp[i]>>high_temp[i];
    }
    ll prev_time=0;
    ll max_temp=m, min_temp=m;
    bool exist=true;

    for(int i=0; i<n; i++){
        max_temp += time[i]-prev_time;
        min_temp -= time[i]-prev_time;

        if(max_temp<low_temp[i] or min_temp>high_temp[i]){
            exist=false;
            break;
        }
        max_temp = min(max_temp, high_temp[i]);
        min_temp = max(min_temp, low_temp[i]);
        prev_time = time[i];
    }

    if(exist){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
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