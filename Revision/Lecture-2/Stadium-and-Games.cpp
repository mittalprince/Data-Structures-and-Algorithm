#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e10
#define INF 1e16
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
    cin>>n;
    set<ll>ans;

    for(int i=0; i<63; i++){
        ll D = pow(2,i)-1;
        if(n==D){
            ans.insert(D+1);
            continue;
        }
        ll s=0, e=inf;
        while(s<=e){
            ll mid = s+(e-s)/2;
            ll t = mid;
            t *= (mid-1);
            t /= 2;

            if(D!=0 and mid > (LLONG_MAX/D)){
                t = LLONG_MAX;
            }
            else{
                t += mid*D;
            }

            if(t==n){
                if(mid&1){
                    ans.insert(mid*(D+1));
                }
                else{
                    break;
                }
            }
            if(t<n){
                s=mid+1;
            }
            else e=mid-1;
        }
    }
    if(ans.empty()){
        cout<<"-1\n";
    }
    else{
        for(ll i: ans){
            cout<<i<<"\n";
        }
    }
    return 0;
}