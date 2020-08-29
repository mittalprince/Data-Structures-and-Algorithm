/*
Ram has an apple tree in his garden. Since he is bored in the lockdown so he thought of decorating the tree.
The nodes of the tree are numbered from 1 to n, where n is the total number of nodes and 1 is the root of the tree. While decorating the tree , Ram will put the light bulb of some color on every leaf node. A node is called happy if all light bulbs in the subtree of that node have different colors.
Ram is interested in the following question: for each k from 1 to n, what is the minimum number of different colors needed to make the number of happy nodes be greater than or equal to k?
A node u is called a leaf node if there is no node v such that to reach v from root, we have to travel through u.

3
1 1

1 1 2
*/

// https://hack.codingblocks.com/app/contests/1783/1737/problem
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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

vector<ll>adj[MAX];

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
    cin>>n;
    
    for(int i=2; i<=n; i++){
        ll x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    vector<ll>ans(n+1, 0);
    vector<bool>visited(n+1, 0);

    function<ll(ll)>dfs_helper;
    dfs_helper =[&](ll src)->ll{
        visited[src]=true;

        for(ll child: adj[src]){
            if(!visited[child]){
                ans[src] += dfs_helper(child);
            }
        }
        if(!ans[src])ans[src]=1;
        return ans[src];
    };

    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            dfs_helper(i);
        }
    }

    sort(ans.begin(), ans.end());

    for(int i=1; i<=n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}