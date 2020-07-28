// https://codeforces.com/contest/287/problem/C
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

    int n;
    cin>>n;
    vector<int> arr(n+1);
    if(n%4>1){
        cout<<"-1\n";
        return 0;
    }
    for(int i=1; i<=n/2; i+=2){
        arr[i] = i+1;
        arr[i+1] = n-i+1;
        arr[n-i]=i;
        arr[n-i+1]=n-i;
    }
    if(n&1){
        arr[n/2+1] = n/2+1;
    }
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}