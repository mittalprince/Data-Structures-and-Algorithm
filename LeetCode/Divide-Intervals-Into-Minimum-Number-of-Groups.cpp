// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
#include<iostream>
#include<vector>
#include<queue>
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

int minGroups(vector<vector<int>>& ints) {
    sort(begin(ints), end(ints));
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto &i : ints) {
        if (!pq.empty() && pq.top() < i[0])
            pq.pop();
        pq.push(i[1]);
    }
    return pq.size();
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