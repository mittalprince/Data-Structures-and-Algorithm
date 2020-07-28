#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations){
    // loigc is we inseet all station capaicty intp pq
    // when the startFuel become negative or 2 we refill it 
    // with available prev station cap which are store in dec oprder in pq
    // so we first use highest possible cap of all available station till ith loc
    
    priority_queue<int>pq;
    int min_req = 0;

    for(int i=0; i<stations.size(); i++){
        if(i==0) startFuel -= stations[i][0];
        else startFuel -= (stations[i][0]-stations[i-1][0]);

        while(!pq.empty() && startFuel < 0){
            startFuel += pq.top();
            pq.pop();
            min_req++;
        }

        if(startFuel < 0) return -1;
        pq.push(stations[i][1]);
    }

    int total_rem_dist=target;
    if(stations.size()){
        total_rem_dist -= stations[stations.size()-1][0];
    }

    startFuel -= total_rem_dist;
    while(!pq.empty() && startFuel < 0){
        startFuel += pq.top();
        pq.pop();
        min_req++;
    }

    if(startFuel < 0) return -1;
    return min_req;
}

int main(){
    int target, startFuel;
    cin>>target>>startFuel;
    int n;
    cin>>n;
    vector<vector<int>>stations(n);
    for(int i=0; i<n; i++){
        int loc, cap;
        cin>>loc>>cap;
        stations[i][0] = loc;
        stations[i][1] = cap;
    }
    return 0;
}