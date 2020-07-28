// https://leetcode.com/problems/course-schedule/
#include<iostream>
#include<vector>
#include<functional>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];

    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }

    vector<bool>visited(numCourses, false), inStack(numCourses, false);

    function<bool(int)>dfs_helper;
    dfs_helper = [&](int src)->bool{
        visited[src]=true;
        inStack[src]=true;

        for(int child: adj[src]){
            if(inStack[child] || (!visited[child] && dfs_helper(child))){
                return true;
            }
        }
        inStack[src]=false;
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

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}

/*
There are a total of numCourses courses you have to take, 
labeled from 0 to numCourses-1.

Some courses may have prerequisites, 
for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, 
is it possible for you to finish all courses?

Here 0 depend on 1 se make a directed edge from 1 to 0 means to complete 0 we must have 1,
so in TS we make an directed edge from jiss par depend karta hai to jo depend karta hai 
(menas 1 par depend karta hai and 0 depend karta hai).
*/
