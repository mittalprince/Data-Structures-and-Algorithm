// https://codeforces.com/contest/922/problem/D
#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<string>arr(n);

    ip(arr, n);

    sort(arr.begin(), arr.end(), [&](string a, string b)->bool{
        string A = a+b;
        string B = b+a;

        ll a_ct=0, b_ct=0, s_count=0;
        for(int i=0; i<A.length(); i++){
            if(A[i]=='s')s_count++;
            else a_ct += s_count;
        }
        s_count=0;
        for(int i=0; i<B.length(); i++){
            if(B[i]=='s')s_count++;
            else b_ct += s_count;
        }

        return a_ct>b_ct;
    });
    
    ll ans=0, s_count=0;
    string t="";
    for(string i: arr){
        // cout<<i<<endl;
        t += i;
    }
    for(int i=0; i<t.length(); i++){
        if(t[i]=='s')s_count++;
        else ans += s_count;
    }
    cout<<ans<<endl;

    return 0;
}