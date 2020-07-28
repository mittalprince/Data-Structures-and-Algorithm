// https://www.hackerearth.com/problem/algorithm/pizza-cutting-2e11a081/
#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    ll n;
    cin>>n;
    unsigned long long int a = n*n;
    a += n+2;

    a /= 2;
    cout<<a<<endl;
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