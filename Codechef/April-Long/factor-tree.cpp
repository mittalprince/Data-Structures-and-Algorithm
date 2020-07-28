#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef unsigned long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define MAX 1000005
#define mod 1000000007

ll factors[MAX] = {0};
// bool prime[MAX]={0};
// ll primesquare[MAX];
vector<ll> path;

void CalculateAllPrime(){
    factors[1]=1;
    for(ll i=2; i<MAX; i++) factors[i]=i;
    for(ll i=4; i<MAX; i+=2) factors[i]=2;
    for(ll i=3; i*i<MAX; i++){
        if(factors[i] == i){
            for(ll j=i*i; j<MAX; j+=i){
                if(factors[j]==j) factors[j]=i;
            }
        }
    }
}

ll findtotalFactors(ll n){
    ll ans=1;
    if(n==1) return ans;
    ll smallest_factor = factors[n];
    ll factor_ct=1;
    ll temp = n/factors[n];

    while(temp != 1){
        if(factors[temp] == smallest_factor) factor_ct++;
        else{
            ans *= (factor_ct+1);
            smallest_factor=factors[temp];
            factor_ct =1;
        }
        temp = temp / factors[temp];
    }
    ans = ans*(factor_ct+1);
    return ans;
}

void SieveOfEratosthenes(ll n, bool prime[], bool primesquare[], ll a[]){
    for (ll i = 2; i <= n; i++)
        prime[i] = true;

    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;

    prime[1] = false;

    for (ll p = 2; p * p <= n; p++){
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }

    ll j = 0;
    for (ll p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}

ll countDivisors(ll n)
{
    if (n == 1)
        return 1;

    bool prime[n + 1], primesquare[n * n + 1];

    ll a[n]; 
    SieveOfEratosthenes(n, prime, primesquare, a);

    ll ans = 1;

    for (ll i = 0;; i++)
    {
        if (a[i] * a[i] * a[i] > n)
            break;
        ll cnt = 1;          
        while (n % a[i] == 0)
        {
            n = n / a[i];
            cnt = cnt + 1;
        }

        ans = ans * cnt;
    }

    if (prime[n])
        ans = ans * 2;

    else if (primesquare[n])
        ans = ans * 3;

    else if (n != 1)
        ans = ans * 4;

    return ans;
}

ll check(ll n){
    ll ct=0;
    for (ll i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if (n / i == i) ct++;
            else ct+=2;
        }
    }
    return ct;
}

void addAllNodes(vector<ll> curr_path){
    ll i=0;
    for(i=0; i<curr_path.size(); i++){
        path.push_back(curr_path[i]);
        // path[global_idx] = curr_path[i];
        // // cout<<"yes "<<path[global_idx]<<" ";
        // global_idx++;
    }
    // path.push_back(curr_path[i]);
    // cout<<endl;
}

void DFSHelper(vector<ll> g[], vector<ll> curr_path, ll src, ll dest, bool visited[]){
    curr_path.push_back(src);
    if(src == dest){
        addAllNodes(curr_path);
        return;
    }

    visited[src]=true;
    bool flag=false;
    for(ll i=0; i<g[src].size(); i++){
        if(!visited[g[src][i]]){
            DFSHelper(g, curr_path, g[src][i], dest, visited);
            flag=true;
        }
    }
    // if(!flag) 
    curr_path.pop_back();
}

void DFS(vector<ll> g[], vector<ll> curr_path, ll nodes, ll src, ll dest){
    bool visited[nodes+1];
    memset(visited, false, sizeof(visited));
    DFSHelper(g, curr_path, src, dest, visited);
}

void addEdge(vector<ll> g[], ll u, ll v){
    g[u].push_back(v);
    g[v].push_back(u);
}

int main(){
    fstIO;
    // CalculateAllPrime();
    ll t;
    cin>>t;
    while(t--){
        ll n,u,v;
        cin>>n;
        vector<ll>g[n+1];
        for(ll i=1; i<n; i++){
            cin>>u>>v;
            addEdge(g, u, v);
        }
        vector<ll> cost(n+1, 0), query_ans, curr_path;
        for(ll i=1; i<=n; i++){
            cin>>cost[i];
        }

        ll q;
        cin>>q;
        while(q--){
            ll src, dest;
            cin>>src>>dest;
            path.clear();
            DFS(g, curr_path, n+1, src, dest);
            ll ans=1;
            for(ll i=0; i<path.size(); i++){
                ans = ((ans%mod)*(cost[path[i]]%mod))%mod;
            }
            // cout<<ans<<endl;
            query_ans.push_back(ans);
        }

        for(ll i=0; i<query_ans.size(); i++){
            // ll temp = countDivisors(query_ans[i]);
            ll temp = check(query_ans[i]);
            cout<<(temp%mod)<<endl;
        }
    }
    return 0;
}