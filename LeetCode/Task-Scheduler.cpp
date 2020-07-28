// https://leetcode.com/problems/task-scheduler/
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

int leastInterval(vector<char>& tasks, int n) {
    int freq[26]={0};
    for(char i: tasks)freq[i-'A']++;

    int mx=0;
    for(int i: freq){
        mx = max(i, mx);
    }
    /*
    * most frequent character will be placed at (n+1)th distance from each other, 
        such that the gap between them remains 'n'.
    * mx-1 as we have total mx freq and we have total mx-1 interval between them.
    * (n+1) as it will be the new starting time next task
    */
    int ans = (mx-1)*(n+1);

    int same=0;
    for(int i: freq){
        same += (i==mx);
    }
    return max((int)tasks.size(), ans+same);
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