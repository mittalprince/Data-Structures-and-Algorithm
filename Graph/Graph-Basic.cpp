#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

// Implement graph using adjancey matrix

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif

    int v,e;
    cin>>v>>e;
    vector<int>adj[v];

    function<void(int,int)>addEdge;
    addEdge = [&](int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    function<void(int v)>print;
    print = [&](int v){
        for(int i=0; i<v; i++){
            cout<<"Adjacency List of Node "<<i<<"\n";
            for(int j: adj[i]){
                cout<<"Edge "<<j<<" ,";
            }
            cout<<endl<<endl;;
        }
    };

    for(int i=0; i<e; i++){
        int u,v;
        cin>>u>>v;
        addEdge(u, v);
    }

    print(v);
    return 0;
}