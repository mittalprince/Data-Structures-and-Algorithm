// https://codeforces.com/contest/1395/problem/B
#include<iostream>
#include<vector>
#include<map>
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

void solve(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;

    vector<pair<int, int> >arr;
    map<pair<int, int>, bool>M;

    while(y){
        arr.push_back({x, y});
        M[{x, y}] = true;
        y--;
    }
    y++;
    arr.push_back({1, y});
    M[{1, y}] = true;
    x=1;

    bool flag=true;
    while(arr.size() < n*m){
        if(flag){
            while(M[{x,y}]){
                x++;
            }
            arr.push_back({x,y});
            x++;
            if(x==n+1){
                y++;
                flag=1-flag;
                x=n;
            }
        }
        else{
            while(M[{x,y}]){
                x--;
            }
            arr.push_back({x,y});
            x--;
            if(x==0){
                y++;
                flag=1-flag;
                x=1;
            }
        } 
    }

    for(auto it: arr){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}