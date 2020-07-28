#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
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

    int n;
    cin>>n;
    vector<int> arr(n);
    ll sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    if(sum&1){
        cout<<"NO\n";
        return 0;
    }
    sum /= 2;
    map<ll ,bool>m;
    ll left_sum=0;
    for(int i: arr){
        left_sum += i;
        m[i]=true;
        if(m.count(left_sum-sum)){
            cout<<"YES\n";
            return 0;
        }
    }
    m.clear();
    ll right_sum=0;
    for(int i=n-1; i>=0; i--){
        right_sum += arr[i];
        m[arr[i]]=true;
        if(m.count(right_sum-sum)){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}