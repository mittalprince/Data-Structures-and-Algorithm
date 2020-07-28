// https://leetcode.com/problems/parallel-courses-ii/
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

int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
    vector<int>adj[n+1];
    vector<int>inDeg(n+1, 0), semester(n+1, -1);

    for(auto it: dependencies){
        adj[it[0]].push_back(it[1]);
        inDeg[it[1]]++;
    }

    queue<int>q;

    for(int i=1; i<=n; i++){
        if(inDeg[i] == 0){
            q.push(i);
            semester[i]=0;
        }
    }

    int currSem=1, ct=0;
    while(!q.empty()){
        int top = q.front();
        q.pop();

        if(ct == k){
            currSem++;
            ct=0;
        }
        ct++;
        if(semester[top] == currSem){
            currSem++;
            ct=0;
        }

        for(int i: adj[top]){
            inDeg[i]--;
            if(inDeg[i] == 0){
                q.push(i);
                semester[i]=currSem;
            }
        }
    }

    return currSem;
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