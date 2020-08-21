// https://codeforces.com/contest/1401/problem/B
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(A, n) for(int i=0; i<n; i++) cin>>A[i];
#define ip1(A, n) for(int i=1; i<=n; i++) cin>>A[i];
#define op(A, n) for(int i=0; i<n; i++) cout<<A[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        ll A[3], B[3];
        ip(A, 3);
        ip(B, 3);

        ll ans=0;
        if(B[1]>A[2]){
            ans += 2*min(A[2], B[1]);
            B[1]-=A[2];
            A[2]=0;
        }
        else{
            ans += 2*min(A[2], B[1]);
            A[2] -= B[1];
            B[1]=0;
        }
        if(B[2]>A[0]){
            B[2]-=A[0];
            A[0]=0;
        }
        else{
            A[0] -= B[2];
            B[2]=0;
        }
        if(B[2]>A[2]){
            B[2]-=A[2];
            A[2]=0;
        }
        else{
            A[2] -= B[2];
            B[2]=0;
        }

        if(B[1]>A[0]){
            B[1]-=A[0];
            A[0]=0;
        }
        else{
            A[0] -= B[1];
            B[1]=0;
        }
        if(B[1]>A[1]){
            B[1]-=A[1];
            A[1]=0;
        }
        else{
            A[1] -= B[1];
            B[1]=0;
        }

        ans -= 2*min(B[2], A[1]);
        cout<<ans<<endl;
    }
    return 0;
}