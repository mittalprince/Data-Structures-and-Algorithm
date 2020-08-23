// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/practice-problems/algorithm/edges-on-path-a62d5276/
#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

vector<int>g[MAX];

map<pair<int, int>, int >amp;
int ct=0;

  
int isNotVisited(int x, vector<int>& path) { 
    int size = path.size(); 
    for (int i=0; i<size; i++)  
        if (path[i] == x)  
            return 0;  
    return 1; 
} 
  
void findpaths(int src, int dst, int v) { 

    queue<vector<int> > q; 
  
    vector<int> path; 
    path.push_back(src); 
    q.push(path); 
    while (!q.empty()) { 
        path = q.front(); 
        q.pop(); 
        int last = path[path.size() - 1]; 
  
        if (last == dst){
            for (int i = 0; i < path.size()-1; i++) {
                int a= path[i];
                int b=path[i+1];
                if(a>b)swap(a,b);
                amp[{a,b}]++;
            } 
            ct++;
        } 

        for(int i: g[last]){
            if(isNotVisited(i, path)){
                path.push_back(i);
                q.push(path);
                path.pop_back();
            }
        }
    } 
} 
  
int main() { 
    fstIO;
    
    int n,m;
    cin>>n>>m;
    
  
    int src, dest;
    cin>>src>>dest;
    src--;
    dest--;

    for(int i=0; i<m; i++){
         int u,v;
         cin>>u>>v;
         u--;
         v--;
         g[u].push_back(v);
         g[v].push_back(u);
    }
  
    findpaths(src, dest, n); 
    int ans=0;
    for(auto it: amp){
        if(it.second == ct){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0; 
} 

