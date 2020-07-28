// https://codeforces.com/contest/492/problem/D
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

    ll n,x,y;
    cin>>n>>x>>y;
    ll ct_x=0, ct_y=0;
    vector<ll>res;

    while(ct_x<x or ct_y<y){
        if((ct_x+1)*y > (ct_y+1)*x){
            ct_y++;
            res.push_back(2);
        }
        else if((ct_x+1)*y < (ct_y+1)*x){
            ct_x++;
            res.push_back(1);
        }
        else{
            res.push_back(3);
            res.push_back(3);
            ct_x++;
            ct_y++;
        }
    }

    for(ll i=0; i<n; i++){
        ll c;
        cin>>c;
        c--;
        int val = res[c%(x+y)];
        if(val == 1){
            cout<<"Vanya\n";
        }
        else if(val == 2){
            cout<<"Vova\n";
        }
        else{
            cout<<"Both\n";
        }
    }
    return 0;
}