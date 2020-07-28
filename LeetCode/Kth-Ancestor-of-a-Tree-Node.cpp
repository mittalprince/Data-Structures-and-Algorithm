// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

class TreeAncestor {
public:
    int parents[50005][20];
    
    TreeAncestor(int n, vector<int>& parent) {
        for(int i=0; i<n; i++){
            parents[i][0] = parent[i];
        }
        
        for(int j=1; j<20; j++){
            for(int i=0; i<n; i++){
                if(parents[i][j-1] == -1)parents[i][j]=-1;
                else parents[i][j] = parents[parents[i][j-1]][j-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int d=19; d>=0; d--){
            if((1<<d)<=k){
                k -= (1<<d);
                node = parents[node][d];
                if(node == -1)return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

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