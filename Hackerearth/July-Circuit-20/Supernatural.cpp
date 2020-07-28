// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/supernatural-cac54bc7/editorial/?layout=old
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
    cin >> n;
    ll cnt = 0;
    for(ll i = 1; i <= 1e7; i++){
        ll te = i;
        ll val = 1;
        bool one = true;
        while(te > 0){
            if(te % 10 == 1) {
                one = false;
                break;
            }
            val = val * (te % 10);
            te /= 10;
        }
        if(val == n && one == true) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}