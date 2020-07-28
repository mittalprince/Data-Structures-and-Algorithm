#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll fstPower(ll a, ll b, ll c){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans = (ans%c * a%c)%c;
        }
        a = ((a%c)*(a%c))%c;
        b /= 2;
    }
    return ans%c;
}
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    cout<<fstPower(a,b,c)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}