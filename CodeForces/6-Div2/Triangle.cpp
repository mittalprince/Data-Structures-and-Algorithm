//https://codeforces.com/contest/6/problem/A
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

void solve(){
    int arr[4];
    ip(arr, 4);

    sort(arr, arr+4);
    int flag=-1;

    for(int i=0; i<2; i++){
        if(arr[i]+arr[i+1] >= arr[i+2]){
            if(arr[i]+arr[i+1] == arr[i+2]){
                flag=0;
            }
            else{
                flag=1;
                break;
            }
        }
    }

    if(flag==-1)cout<<"IMPOSSIBLE\n";
    else if(flag==0)cout<<"SEGMENT\n";
    else cout<<"TRIANGLE\n";
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