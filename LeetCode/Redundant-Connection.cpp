#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

class Solution {
public:
    class DSU{
        vector<int>parent, rank;
        
        public:
        int totalComponents;
        
        DSU(int n){
            totalComponents=n;
            parent = vector<int>(n);
            rank = vector<int>(n);
            
            for(int i=0; i<n; i++){
                parent[i]=i;
                rank[i]=0;
            }
        }
        
        int get(int a){
            if(parent[a] == a) return a;
            return parent[a] = get(parent[a]);
        }
        
        void union_sets(int a, int b){
            a = get(a);
            b = get(b);
            
            if(a != b){
                if(rank[a]<rank[b]){
                    swap(a, b);
                }
                
                parent[b]=a;
                if(rank[a]==rank[b])rank[a]++;
                totalComponents--;
            }
        }
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        
        DSU g(n+1);
        vector<int>ans;
        
        for(auto it: edges){
            if(g.get(it[0]) == g.get(it[1])){
                ans = it;
            }
            else g.union_sets(it[0], it[1]);
        }
        
        return ans;
    }
};

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