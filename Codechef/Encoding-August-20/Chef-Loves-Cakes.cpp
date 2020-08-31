// https://www.codechef.com/ENAU2020/problems/ECAUG201
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];

ll GCD(ll a, ll b){
    if(b==0)return a;
    return GCD(b, a%b);
}

ll LCM(ll a, ll b){
    return a/GCD(a,b)*b;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        cout<<LCM(n,m)<<"\n";
    }
    return 0;
}