// https://codeforces.com/contest/20/problem/B
#include<iostream>
#include<vector>
#include<iomanip>
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

    double x,y,a,b,c,d;
    cin>>a>>b>>c;
    
    cout<<fixed<<setprecision(10);
    if(!a and !b and !c){
        cout<<"-1";
        return 0;
    }
    if(b*b>=4*a*c){
        if(!a){
            if(b) cout<<"1\n"<<(-c/b);
            else if(c) cout<<"0";
            return 0;
        }
        d = sqrt(b*b-4*a*c);
        x = (-b + d) / (2*a);
        y = (-b - d) / (2*a);
        if(x==y)
            cout<<"1\n"<<x;
        else
            cout<<"2\n"<<min(x,y)<<"\n"<<max(x,y);
    }
    else cout<<0;

    return 0;
}