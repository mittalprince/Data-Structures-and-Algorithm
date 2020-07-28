#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

ll n,m;
ll arr[100001];

void solve(){
    ll sum=0;
    ll power[60]={0};

    for(ll i=0; i<m; i++){
        power[int(log2(arr[i]))]++;
        sum += arr[i];
    }

    if(sum<n){
        cout<<"-1\n";
        return;
    }

    ll ans=0;
    int i=0;

    while(i<=60){
        if((n>>i)&1){
            if(power[i]) power[i]--;
            else{
                while(i<=60 && !power[i]){
                    power[i]++;
                    i++;
                    ans++;
                }
                power[i]--;
                continue;
            }
        }
        power[i+1]+=power[i]/2;
        i++;
    }

    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         cin>>n>>m;
         ip(arr, m);
         solve();
    }
    return 0;
}