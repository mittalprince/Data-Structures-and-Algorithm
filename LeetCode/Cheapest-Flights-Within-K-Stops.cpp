// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<int>> dist(K+2, vector<int>(n, INT_MAX));

    for(int i=0; i<=K+1; i++){
        dist[i][src]=0;
    }

    for(int i=1; i<=K+1; i++){
        for(auto it: flights){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(dist[i-1][u] != INT_MAX){
                dist[i][v] = min(dist[i][v], dist[i-1][u]+w);
            }
        }
    }

    return dist[K+1][dst]==INT_MAX?-1:dist[K+1][dst];
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