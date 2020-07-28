// https://leetcode.com/problems/time-needed-to-inform-all-employees/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<functional>
#include<algorithm>
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

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode():val(0),left(NULL),right(NULL){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, vector<int> >adj;

    for(int i=0; i<n; i++){
        if(i!=-1) adj[manager[i]].push_back(i);
    }

    int ans=0;

    function<int(int)>dfs_helper;
    dfs_helper = [&](int src)->int{
        int t=0;

        if(adj.count(src)){
            for(int child: adj[src]){
                t = max(t,dfs_helper(child));
            }
            t += informTime[src];
        }  
        return t;
    };

    ans = dfs_helper(headID);
    return ans;
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