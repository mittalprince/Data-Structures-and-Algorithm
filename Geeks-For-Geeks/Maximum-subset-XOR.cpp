// https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1
// https://www.geeksforgeeks.org/find-maximum-subset-xor-given-set/
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
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);

    int idx=0;
    for(int i=31; i>=0; i--){
        int maxidx=idx;
        int maxElmt = -inf;

        for(int j=idx; j<n; j++){
            if((arr[j]&(1<<i)) and maxElmt < arr[j]){
                maxidx = j;
                maxElmt = arr[j];
            }
        }

        if(maxElmt == -inf){
            continue;
        }

        for(int j=0; j<n; j++){
            if((arr[j]&(1<<i)) and j != maxidx){
                arr[j] ^= arr[maxidx];
            }
        }
        swap(arr[idx], arr[maxidx]);
        idx++;
    }

    int ans=0;
    for(int i: arr){
        ans ^= i;
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