// https://codeforces.com/problemset/problem/525/B
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
#define MAX 200005

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll ct[MAX]={0};
    
    string s;
    cin>>s;
    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        ll x;;
        cin>>x;
        ct[x-1]++;
    }
    int n=s.length();
    for(int i=0; i<s.length()/2; i++){
        if(i>0)ct[i] += ct[i-1];
        ct[i] = ct[i]&1;
        if(ct[i]){
            swap(s[i], s[n-i-1]);
        }
    }
    cout<<s<<endl;
    return 0;
}