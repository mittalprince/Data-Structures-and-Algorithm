// https://codeforces.com/contest/1038/problem/A
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

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    int freq[26]={0};
    for(char i: s){
        freq[i-'A']++;
    }
    
    int min_len=n;
    for(int i=0; i<k; i++){
        min_len = min(min_len, freq[i]);
    }
    cout<<min_len*k<<endl;
    return 0;
}