// https://codeforces.com/contest/433/problem/A
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
    vector<int> arr(2, 0);
    
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x==100)arr[0]++;
        else arr[1]++;
    }

    if(arr[0]&1){
        cout<<"NO\n";
        return 0;
    }
    if(arr[0]==0 and arr[1]&1){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}