// https://leetcode.ca/2016-08-17-261-Graph-Valid-Tree/
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

vector<int>p;
bool validTree(int n, vector<vector<int>>&edges){
    p.resize(n);
    for(int i=0; i<n; i++) p[i] = i;
    for(auto& it: edges){
        int a = it[0], b = it[1];
        if(find(a) == find(b))return false;
        p[find(a)] = find(b);
        --n;
    }
    return n == 1;
}
int find(int a){
    if(p[a] != a) p[a] = find(p[a]);
    return p[a];
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