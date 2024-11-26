// https://leetcode.com/problems/find-champion-ii/
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

int findChampion(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);
    for(int i=0; i<edges.size(); i++){
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    int ans=-1;
    for(int i=0; i<n; i++){
        if(adj[i].size()==0){
            if(ans!=-1) return -1;
            ans = i;
        }
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}