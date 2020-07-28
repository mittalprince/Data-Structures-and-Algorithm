// https://codeforces.com/contest/1165/problem/C
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
    string s;
    cin>>s;

    for(int i=0; i<s.length();){
        if(s[i] == s[i+1]){
            s.erase(s.begin()+i+1);
        }
        else i+=2;
    }
    if(s.length()&1)s.pop_back();
    cout<<n-s.length()<<endl;
    cout<<s<<endl;
    
    return 0;
}