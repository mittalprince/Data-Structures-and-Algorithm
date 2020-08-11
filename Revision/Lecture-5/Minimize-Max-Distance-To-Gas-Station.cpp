/*
https://code.dennyzhang.com/minimize-max-distance-to-gas-station
On a horizontal number line, we have gas stations at positions stations[0], stations[1], …, stations[N-1], where N = stations.length.
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.

Example:

Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:

stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.
*/

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

bool canPlace(vector<int>&arr, int k, int min_dist_between_stations){
    int total_place_sattion=0;
    for(int i=1; i<arr.size(); i++){
        total_place_sattion += (int)(arr[i]-arr[i-1])/min_dist_between_stations;
    }
    return total_place_sattion<=k;
}

double minmaxgasDist(vector<int>&arr, int k){
    int n=arr.size();
    int s=0, e=1e8;

    while(e-s>1e-6){ // as Answers within 10^-6 of the true value will be accepted as correct
        double mid = (s+e)/2;
        if(canPlace(arr, k, mid)){
            // if I can place atmost k station, then two case
            // 1. place total k station so check for minimum val of D so dec mid and check
            // 2. if I can not place k station at mid dist means we have to decr the mid so that can place exactly k station, so again dec 
            e=mid;
        }
        else s=mid;
    }
    return s;
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