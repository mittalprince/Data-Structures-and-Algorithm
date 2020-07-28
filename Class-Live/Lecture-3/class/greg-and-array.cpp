#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

int main(){
    ll n,m,k;
    ll arr[MAX]={0}, l[MAX]={0}, r[MAX]={0}, d[MAX]={0}, ct[MAX]={0}, diff[MAX]={0};

    cin>>n>>m>>k;
    ip(arr, n);
    for(ll i=1; i<=m; i++){
        cin>>l[i]>>r[i]>>d[i];
    }
    for(ll i=0; i<k; i++){
        ll x,y;
        cin>>x>>y;
        ct[x]++;
        ct[y+1]--;
    }
    //prefix sum of each operation i.e how many time ith operation we perform
    for(ll i=1; i<=m; i++){
        ct[i] += ct[i-1];
    }
    for(ll i=1; i<=m; i++){
        diff[l[i]] += ct[i]*d[i];
        diff[r[i]+1] -= ct[i]*d[i];
    }

    for(ll i=1; i<=n; i++){
        diff[i] += diff[i-1];
    }
    for(ll i=1; i<=n; i++){
        cout<<diff[i]+arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}