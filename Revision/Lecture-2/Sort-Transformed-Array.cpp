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

ll func(ll a, ll b, ll c, ll x){
    return (a*x*x + b*x + c);
}

vector<ll> sortTransformedArray(vector<ll>&arr, ll a, ll b, ll c){
    ll n=arr.size();
    ll left=0, right=n-1;
    ll idx = (a>=0)?n-1:0;

    vector<ll>ans(n);

    while(left<=right){
        if(a>=0){
            ll opt1 = func(a,b,c,arr[left]);
            ll opt2 = func(a,b,c,arr[right]);
            if(opt1>opt2){
                ans[idx]=opt1;
                left++;
            }
            else{
                ans[idx]=opt2;
                right--;
            }
            idx--;
        }
        else{
            ll opt1=func(a,b,c,arr[left]);
            ll opt2=func(a,b,c,arr[right]);

            if(opt1<opt2){
                ans[idx]=opt1;
                left++;
            }
            else{
                ans[idx]=opt2;
                right--;
            }
            idx++;
        }
    }
    return ans;
}
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);

    vector<ll>ans = sortTransformedArray(arr, a, b, c);
    for(ll i: ans){
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