// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
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

bool isPossible(vector<int>&dist, double hour, int speed){
    double ans = 0;
    for(int i=0; i<dist.size(); i++){
        double t = dist[i]*1.0/speed;
        if(i!=dist.size()-1) ans += ceil(t);
        else ans += t;
        if(ans > hour)return false;
    }
    return ans<=hour;
}
int minSpeedOnTime(vector<int>& dist, double hour) {
    int s=1, e=1e9;
    int minSpeed = -1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(isPossible(dist, hour, mid)){
            minSpeed = mid;
            e = mid-1;
        }
        else s = mid+1;
    }
    return minSpeed;
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