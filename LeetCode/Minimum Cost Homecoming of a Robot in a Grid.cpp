// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/
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

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int sum = 0;
    while(startPos[0] != homePos[0])
        sum+= startPos[0] < homePos[0] ? rowCosts[++startPos[0]]  : rowCosts[--startPos[0]];
    while(startPos[1] != homePos[1])
        sum+=startPos[1] < homePos[1] ? colCosts[++startPos[1]]  : colCosts[--startPos[1]];
    return sum;
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