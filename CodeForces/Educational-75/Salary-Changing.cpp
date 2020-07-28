// https://codeforces.com/contest/1251/problem/D
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf int(1e9)+100
#define INF 1e16
#define MOD 1000000007
#define MAX 200005

ll n,total_money;
pair<ll ,ll>arr[MAX];

bool isPossible(ll max_median){
    // to make max_median as the median we need ct>=(n+1)/2
    /*
    Case 1. when the max limit of getting salary is <max_median then it come before max_median
    so ct do not updte and we assign min salary to him

    Case 2. when the min limit of getting salary is >= max_median then is comes after the max_median
    so update ct and assign min salary to him

    Case 3. when max_median in within theri salary range then we assign rem = (0, (n+1)/2-ct) person max_median slary and 
    other person their min salary
    */
    ll ct=0;
    ll amount_paid=0;
    vector<ll>t;
    for(int i=0; i<n; i++){
        if(arr[i].second<max_median){
            amount_paid += arr[i].first;
        }
        else if(arr[i].first>=max_median){
            amount_paid += arr[i].first;
            ct++;
        }
        else{
            t.push_back(arr[i].first);
        }
    }
    ct = max(0ll, (n+1)/2-ct);
    if(t.size()<ct)return false;

    sort(t.begin(), t.end());
    for(int i=0; i<t.size(); i++){
        if(i<t.size()-ct){
            amount_paid += t[i];
        }
        else{
            amount_paid += max_median;
        }
    }
    // check the total amount_paid is less than total_money or not
    return amount_paid <= total_money;
}

void solve(){
    cin>>n>>total_money;
    for(int i=0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n);
    ll ans=0;

    ll l=1, r=inf;
    while(l<=r){
        ll mid = l+(r-l)/2;
        if(isPossible(mid)){
            ans = mid;
            l=mid+1;
        }
        else r=mid-1;
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