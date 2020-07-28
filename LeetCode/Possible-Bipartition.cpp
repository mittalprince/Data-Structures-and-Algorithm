#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

bool possibleBipartition(int N, vector<vector<int>>& d){
    vector<int>color(N+1, 0);
    vector<vector<int>> adj(N+1);

    for(auto it: d){
        adj[it[0]].push_back(it[1]-1);
        adj[it[1]].push_back(it[0]-1);
    }

    function<bool(int, int)> dfs;
    dfs = [&](int v, int c)->bool{

        color[v]=c;
        for(auto e: adj[v]){
            if(color[v] == color[e]) return false;
            else{
                if(color[e]==0){
                    bool t= dfs(e, -1*color[v]);
                }
            }
        }
        return true;
    };

    for(int i=1; i<=N; i++){
        if(color[i] == 0){
            bool check = dfs(i, 1);
            if(!check) return false;
        }
    }
    return true;
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