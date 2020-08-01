// https://codeforces.com/contest/1332/problem/B
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

int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};

void solve(){
    int n;
    cin>>n;

    int arr[n];
    int freq[11]={0};
    int total_colr_used=0;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        for(int j=0; prime[j]*prime[j]<=x; j++){
            if(x%prime[j]==0){
                if(freq[j]==0){
                    total_colr_used++;
                    freq[j]=total_colr_used;
                }
                arr[i]=freq[j];
                break;
            }
        }
    }

    cout<<total_colr_used<<endl;
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
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