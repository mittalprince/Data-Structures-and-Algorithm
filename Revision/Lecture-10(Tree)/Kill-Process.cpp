// https://massivealgorithms.blogspot.com/2017/05/leetcode-582-kill-process.html
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>
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

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill){
    vector<int> ans;
    unordered_map<int, vector<int>> adj;

    for(int i=0; i<pid.size(); i++){
        adj[ppid[i]].push_back(pid[i]);
    }

    function<void(int)>dfs_helper;
    dfs_helper = [&](int process){
        ans.push_back(process);
        for(int i: adj[process]){
            dfs_helper(i);
        }
    };

    dfs_helper(kill);
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