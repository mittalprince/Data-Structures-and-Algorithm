#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n=stations.size();
    if(n==0){
        return (target<=startFuel)?0:-1;
    }

    priority_queue<int>pq;

    int min_fuel_req=0;

    for(int i=0; i<n; i++){
        if(i==0) startFuel -= stations[i][0];
        else startFuel -= (stations[i][0]-stations[i-1][0]);

        while(!pq.empty() && startFuel<0){
            startFuel += pq.top();
            pq.pop();
            min_fuel_req++;
        }

        if(startFuel<0) return -1;
        pq.push(stations[i][1]);
    }

    int rem_dist_fuel = startFuel-(target-stations[n-1][0]);
    while(!pq.empty() && rem_dist_fuel<0){
        rem_dist_fuel += pq.top();
        pq.pop();
        min_fuel_req++;
    }

    return rem_dist_fuel<0?-1:min_fuel_req;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}