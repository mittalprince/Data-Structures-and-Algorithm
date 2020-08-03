// https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/palindrome-change-3e337ebf/description/?layout=old
#include<iostream>
#include<vector>
#include<climits>
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

    string S;
    cin>>S;

    string u, v;
    int n=S.length();
    u = S.substr(0, n/2);
    v = S.substr((n+1)/2);
    reverse(v.begin(), v.end());

    vector<vector<ll>> dist(26, vector<ll>(26, INT_MAX));
    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        char x,y;
        ll cost;
        cin>>x>>y>>cost;
        dist[x-'a'][y-'a']=min(dist[x-'a'][y-'a'], cost);
        dist[y-'a'][x-'a']=min(dist[y-'a'][x-'a'], cost);
    }

    for(int i=0; i<26; i++)dist[i][i]=0;

    for(int k=0; k<26; k++){
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    ll min_cost=0;

    for(ll i=0; i<u.length(); i++){
        if(u[i] != v[i]){
            ll curr_min_cost=INT_MAX;
            for(int j=0; j<26; j++){
                if(dist[u[i]-'a'][j]+dist[v[i]-'a'][j] < curr_min_cost){
                    curr_min_cost = dist[u[i]-'a'][j]+dist[v[i]-'a'][j];
                }
            }
            min_cost += curr_min_cost;
        }
    }

    cout<<min_cost<<endl;
    return 0;
}