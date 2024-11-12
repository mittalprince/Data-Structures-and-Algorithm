// https://leetcode.com/problems/number-of-provinces/
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

vector<int> parent;          
int totalcomp;
int get(int a){
    if(a==parent[a]) return a;
    return parent[a] = get(parent[a]);
}
void unite(int a, int b){
    a = get(a);
    b = get(b);
   if(a != b){
       parent[b] = a;
        totalcomp--;
    }
}
int solve(vector<vector<int>>& M){
    for(int i=0; i<M.size(); i++){
        for(int j=i+1; j<M[i].size(); j++){
            if(M[i][j])
                unite(i,j);
        }
    }
    return totalcomp;
}
int findCircleNum(vector<vector<int>>& M) {
    if (M.empty()) return 0;

    int n = M.size();
    totalcomp = n;

    parent.resize(n);
    for(int i=0; i<n; i++)
        parent[i] = i;

    // solve(M);
    return solve(M);
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