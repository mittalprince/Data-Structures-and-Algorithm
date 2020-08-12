// https://leetcode.com/problems/minimum-number-of-refueling-stops/
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

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=stations.size();

    if(n==0){
        return (startFuel>=target)?0:-1;
    }

    priority_queue<int>pq;
    int min_fuel_req=0;

    for(int i=0; i<n; i++){
        if(i==0) startFuel -= stations[i][0];
        else startFuel -= (stations[i][0] - stations[i-1][0]);

        while(!pq.empty() and startFuel<0){
            startFuel += pq.top();
            pq.pop();
            min_fuel_req++;
        }
        if(startFuel<0)return -1;
        pq.push(stations[i][1]);
    }

    startFuel-=(target-stations[n-1][0]);

    while(!pq.empty() and startFuel<0){
        startFuel += pq.top();
        pq.pop();
        min_fuel_req++;
    }

    if(startFuel<0)return -1;
    return min_fuel_req;
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