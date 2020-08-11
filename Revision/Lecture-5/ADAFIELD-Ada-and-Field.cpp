// https://www.spoj.com/problems/ADAFIELD/
#include<iostream>
#include<vector>
#include<set>
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

    fstIO;

    int t;
    cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;

        multiset<ll>sx,sy,x,y;
        sx.insert(n);
        sy.insert(m);
        x.insert(0); x.insert(n);
        y.insert(0); y.insert(m);

        for(int i=0; i<q; i++){
            ll a,b;
            cin>>a>>b;
            if(a==0){
                if(x.find(b) != x.end()){
                    cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; 
                    continue;
                }
                auto small = x.lower_bound(b); small--;
                auto large = x.upper_bound(b);

                x.insert(b);
                sx.erase(sx.find(*large-*small));
                sx.insert(b-*small);
                sx.insert(*large-b);
                cout<<(*(--sx.end()))*(*(--sy.end()))<<endl; 
            }
            else{
                if (y.find(b) != y.end()){
                    cout<<(*(--sx.end())) * (*(--sy.end()))<<endl;
                    continue;
                }
                auto small = y.lower_bound(b);
                small--;
                auto large = y.upper_bound(b);

                y.insert(b);
                sy.erase(sy.find(*large - *small));
                sy.insert(b-*small);
                sy.insert(*large-b);
                cout << (*(--sx.end())) * (*(--sy.end())) << endl;
            }
        }
    }
    return 0;
}