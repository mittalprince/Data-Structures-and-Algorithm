// https://leetcode.com/problems/coordinate-with-maximum-network-quality/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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

double dist(vector<int> & a, vector<int> & b) {
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
}

vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = towers.size();
    vector<int> value(n);
    int ans = -1, ind = -1;

    for (int i = 0; i < n; i++) {
        int quality = 0;
        for (int j = 0; j < n; j++) {
            double d = dist(towers[i], towers[j]);
            if (d <= radius) {
                quality += (int)(towers[j][2] / (1+d));
            }
        }
        if (quality == ans) {
            if (towers[i] < towers[ind]) {
                ind = i;
            }
        } else if (quality > ans) {
            ind = i;
            ans = quality;
        }
    }
    vector<int> pos = {towers[ind][0], towers[ind][1]};
    return pos;
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