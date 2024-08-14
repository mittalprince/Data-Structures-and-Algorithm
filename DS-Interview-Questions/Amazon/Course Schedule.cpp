// https://leetcode.com/problems/course-schedule/
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

// hint -> check if cycle exist in directed acylic graph -> if no possible (ans yes)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    vector<int> adj[numCourses];
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    vector<bool> visited(numCourses, false), inStack(numCourses, false);
    function<bool(int)>dfs_helper = [&](int src)->bool{
        visited[src]=true;
        inStack[src]=true;

        for(int child: adj[src]){
            if(inStack[child] || (!visited[child] && dfs_helper(child)))return true;
        }
        inStack[src] = false;
        return false;
    };

    for(int i=0; i<numCourses; i++){
        if(!visited[i]){
            if(dfs_helper(i))return false;
        }
    }
    return true;
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