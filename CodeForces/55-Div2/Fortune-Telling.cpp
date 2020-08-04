// https://codeforces.com/contest/59/problem/B
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
    int n;
    cin>>n;
    vector<int>odd, even;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x&1)odd.push_back(x);
        else even.push_back(x);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int n1 = odd.size();
    int n2 = even.size();

    int ans=0;
    if(n1%2==0)n1--;
    for(int i=0; i<n1; i++){
        ans += odd[i];
    }

    if(ans==0){
        cout<<"0\n";
        return;
    }
    for(int i=0; i<n2; i++){
        ans += even[i];
    }
    
    cout<<ans<<endl;
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