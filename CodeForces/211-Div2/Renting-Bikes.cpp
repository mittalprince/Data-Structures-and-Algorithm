// https://codeforces.com/contest/363/problem/D
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

ll n,m,a;
vector<ll>personal_money, bike_price;
ll curr_sum=0, sum=0, ans=0;
vector<ll> amt_used_from_personal_money(100001, 0);

bool isPossible(ll max_bikes){
    curr_sum=0;
    ll j=n-1;
    ll total_money_available=a;

    for(ll i=max_bikes-1; i>=0; i--){
        amt_used_from_personal_money[j]=0;
        if(personal_money[j]>=bike_price[i]){
            amt_used_from_personal_money[j] = bike_price[i];
        }
        else{
            amt_used_from_personal_money[j] = personal_money[j];
            total_money_available -= (bike_price[i]-personal_money[j]);
        }
        if(total_money_available<0){
            return false;
        }
        j--;
    }

    curr_sum=0;
    j=n-1;
    for(ll i=0; i<max_bikes; i++){
        if(total_money_available>0){
            ll t = min(amt_used_from_personal_money[j], total_money_available);
            amt_used_from_personal_money[j] -= t;
            total_money_available -= t;
        }
        curr_sum += amt_used_from_personal_money[j];
        j--;
    }
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m>>a;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        personal_money.push_back(x);
    }
    for(ll i=0; i<m; i++){
        ll x;
        cin>>x;
        bike_price.push_back(x);
    }

    sort(personal_money.begin(), personal_money.end());
    sort(bike_price.begin(), bike_price.end());

    ll s=0, e=min(n,m);
    while(s<=e){
        ll mid = s+(e-s)/2;
        if(isPossible(mid)){
            ans=mid;
            sum=curr_sum;
            s=mid+1;
        }
        else e=mid-1;
    }
    cout<<ans<<" "<<sum<<endl;
    return 0;
}