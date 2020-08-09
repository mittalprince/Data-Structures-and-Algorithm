// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include<iostream>
#include<vector>
#include<cstring>
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

int memo[105][105];
vector<int> v;

int f(int a, int b){
    if(b-a==1) return 0;

    if(memo[a][b]!=-1) return memo[a][b];

    int x=INT_MAX;

    for(int i=a+1;i<b;i++)
        x=min(v[b]-v[a]+f(a,i)+f(i,b),x);

    memo[a][b]=x;
    return x;
}

int minCost(int L, vector<int>& cuts) {
    int n=cuts.size();

    v.clear();
    v.push_back(0);
    for(int i=0;i<n;i++)
    {
        v.push_back(cuts[i]);
    }
    v.push_back(L);
    sort(v.begin(), v.end());
    memset(memo,-1,sizeof(memo));
    return f(0, n+1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}