// https://codeforces.com/contest/1401/problem/C
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(A, n) for(int i=0; i<n; i++) cin>>A[i];
#define ip1(A, n) for(int i=1; i<=n; i++) cin>>A[i];
#define op(A, n) for(int i=0; i<n; i++) cout<<A[i]<<" ";
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

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>A(n);
        ip(A, n);

        vector<ll>B(n);
        B = A;
        
        sort(A.begin(), A.end());
        ll mi = A[0];

        if(B==A){
            cout<<"YES\n";
        }
        else{
            bool flag=true;
            for(int i=0; i<n; i++){
                if(A[i] != B[i]){
                    if(B[i]%mi){
                        cout<<"NO\n";
                        flag=false;
                        break;
                    }
                }
            }
            if(flag)
            cout<<"YES\n";
        }
    }
    return 0;
}