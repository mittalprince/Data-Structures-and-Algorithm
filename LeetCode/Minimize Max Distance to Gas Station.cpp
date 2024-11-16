// https://leetcode.ca/all/774.html
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

int ok(double x, vector<int> &v) {
    int ret = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        ret += ceil((v[i + 1] - v[i]) / x) - 1;
    }
    return ret;
}

double findSmallestMaxDist(vector<int> &stations, int K) {
    double low = 0;
    int n = stations.size();
    double high = stations[n - 1] - stations[0];
    while (high - low >= 1e-6) {
        double mid = (low + high) / 2.0;
        int x = ok(mid, stations);
        if (x > K) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return high;
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