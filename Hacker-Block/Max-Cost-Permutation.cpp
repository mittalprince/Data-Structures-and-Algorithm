#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int ans=0;
int n;
int arr[25]={0};

void solve(){

    for(int i=0; i<(1<<n); i++){
        int t=0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                t += (arr[j]*j);
            }
        }
        ans = max(ans, t);
    }
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    ip(arr, n);
    solve();
    cout<<ans<<endl;
    return 0;
}