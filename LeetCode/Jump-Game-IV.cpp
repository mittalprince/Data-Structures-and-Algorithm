//https://leetcode.com/problems/jump-game-iv/
#include<iostream>
#include<vector>
#include<unordered_map>
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

int minJumps(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = arr.size();
    unordered_map<int, vector<int>> indicesOfValue;
    for (int i = 0; i < n; i++)
        indicesOfValue[arr[i]].push_back(i);

    vector<bool> visited(n); 
    visited[0] = true;

    queue<int> q; 
    q.push(0);

    int step = 0;
    while (!q.empty()) {
        for (int size = q.size(); size > 0; --size) {
            int i = q.front(); 
            q.pop();

            if (i == n - 1) return step; // Reached to last index

            vector<int>& next = indicesOfValue[arr[i]];
            next.push_back(i - 1); next.push_back(i + 1);

            for (int j : next) {
                if (j >= 0 && j < n && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
            next.clear(); // avoid later lookup indicesOfValue arr[i]
        }
        step++;
    }
    return 0;
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