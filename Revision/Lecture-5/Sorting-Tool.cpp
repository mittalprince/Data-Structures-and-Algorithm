// https://www.codechef.com/problems/KJCP01
#include<iostream>
#include<vector>
#include<functional>
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
#define MAX 100005

class Pair{
    public:
    ll freq, idx, val;

    Pair():freq(0),idx(0),val(0){}
};

void solve(){
    int n,m;
    cin>>n>>m;
    Pair arr[MAX];
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(arr[x].freq==0){
            arr[x].freq=1;
            arr[x].idx=i;
            arr[x].val=x;           
        }
        else arr[x].freq++;
    }

    sort(arr, arr+MAX, [&](const Pair a, const Pair b)->bool{
        if(a.freq==b.freq){
            return a.idx<b.idx;
        }
        return a.freq>b.freq;
    });

    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].freq; j++)
            cout<<arr[i].val<<" ";
    }
    cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}