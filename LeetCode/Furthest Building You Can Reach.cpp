// https://leetcode.com/problems/furthest-building-you-can-reach/
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

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;

    for (int i = 0; i < heights.size() - 1; i++) {
        if (heights[i] >= heights[i + 1])
            continue;

        int diff = heights[i + 1] - heights[i];
        pq.push(diff);
        bricks -= diff;

        if (bricks >= 0)
            continue;

        if (ladders == 0)
            return i;

        bricks += pq.top(); pq.pop(); 
        ladders--;
    }

    return heights.size() - 1;
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