// https://leetcode.com/problems/course-schedule-ii/
#include<iostream>
#include<vector>
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

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int>adj[numCourses];
    vector<int>inDegree(numCourses, 0), ans;

    for(auto &it: prerequisites){
        adj[it[1]].push_back(it[0]);
        inDegree[it[0]]++;
    }

    queue<int>q;
    for(int i=0; i<numCourses; i++){
        if(inDegree[i] == 0)q.push(i);
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        ans.push_back(top);

        for(int child: adj[top]){
            inDegree[child]--;
            if(inDegree[child]==0){
                q.push(child);
            }
        }
    }

    if(ans.size() == numCourses)return ans;
    else return {};
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