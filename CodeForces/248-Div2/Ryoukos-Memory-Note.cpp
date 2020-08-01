// https://codeforces.com/contest/433/problem/C
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

void solve(){
    int n,m;
    cin>>n>>m;

    ll arr[m];
    ip(arr, m);

    if(n==1 or m==1){
        cout<<0<<endl;
        return;
    }

    vector<vector<ll> >adj(n+1);
    ll ans=0;


    // First we store the all adjacent of number (but neighbour must have diff val)
    for(int i=0; i<m-1; i++){
        if(arr[i] != arr[i+1]){
            adj[arr[i]].push_back(arr[i+1]);
            adj[arr[i+1]].push_back(arr[i]);
            
            ans += abs(arr[i]-arr[i+1]);
        }
    }

    ll min_ans = ans; // the possible min_ans

    for(int i=1; i<=n; i++){
        if(adj[i].size()){
            // now traverse all the adjaceny list of a page
            sort(adj[i].begin(), adj[i].end());
            ll diff=0, sum=0;
            for(ll j: adj[i]){
                diff += abs(i-j);
                sum += j;
            }

            ll sum1=0;
            ll sum2=sum;
            ll sz = adj[i].size();

            for(ll j=0; j<sz; j++){ // now we try to merge i to adj[i][j] and then check what will be ans
                sum1 += adj[i][j];
                sum2 -= adj[i][j];

                // now merge i to adj[i][j]
                // so the no of pages he need to turn will be
                // since we have sum of first j-1 element in sum1 and j+1 to sz
                // so first j-1 element ka diff adj[i][j] se nikala -> ((j+1)*adj[i][j] - sum1)
                // simillary j+t to sz elemnt ka diff adj[i][j] se nikala -> (sum2 -((sz-j-1)*adj[i][j])
                ll val = (sum2 -((sz-j-1)*adj[i][j]) + ((j+1)*adj[i][j] - sum1));

                // then actual diff ko ans se - kia then val ko add kia
                min_ans = min(min_ans, ans-diff+val);
            }
        }
    }

    cout<<min_ans<<endl;
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