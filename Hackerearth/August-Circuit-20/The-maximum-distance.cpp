// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/lazy-segment-0186d695/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
 
int main(){
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    fstIO;
 
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);
 
    ll q;
    cin>>q;
    for(int i=0; i<q; i++){
        int type;
        ll l,r,x;
        cin>>type;
        if(type==1 or type==2){
            cin>>l>>r>>x;
            l--;r--;
            for(ll j=l; j<=r; j++){
                if(type==1) arr[j]+=x;
                else arr[j] *= x;
            }
        }
        else{
            ll z;
            cin>>z;
            // cout<<z<<" h \n";
            auto it = find(arr.begin(), arr.end(), z);
            auto itrev = find(arr.crbegin(), arr.crend(), z);
            cout<<(n - (itrev - arr.rbegin()) - 1) - (it - arr.begin()) + 1<<"\n";
        }
    }
    return 0;
}