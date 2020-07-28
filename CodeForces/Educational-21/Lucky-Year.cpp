// https://codeforces.com/contest/808/problem/A
#include<iostream>
#include<vector>
#include<cmath>
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
    string s = to_string(n);
    if(s.length() == 1){
        cout<<"1\n";
        return 0;
    }
    int val = s[0]-'0';
    int dig = (val+1)*pow(10, s.length()-1);
    int diff = dig-n;
    cout<<diff<<endl;
    return 0;
}