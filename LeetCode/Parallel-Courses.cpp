#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#include<unordered_map>
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

int minimumSemesters(int N, vector<vector<int> >&relations){
    vector<int>adj[N+1];
    vector<int>inDeg(N+1, 0);

    for(auto it: relations){
        adj[it[0]].push_back(it[1]);
        inDeg[it[1]]++;
    }

    
    queue<int>q;
    int level=0, courses=0;

    for(int i=1; i<=N; i++){
        if(inDeg[i] == 0)q.push(i);
    }

    while(!q.empty()){
        ll sz = q.size();
        courses += sz;
        for(int i=0; i<sz; i++){
            int top = q.front();
            q.pop();

            for(int j: adj[top]){
                inDeg[j]--;
                if(inDeg[j]==0){
                    q.push(j);
                }
            }
        }
        level++;
    }
    // cout<<courses<<" "<<level<<endl;
    return courses==N?level:-1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    vector<vector<int> >arr;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        arr.push_back({u,v});
    }
    
    cout<<minimumSemesters(n, arr)<<endl;
    return 0;
}