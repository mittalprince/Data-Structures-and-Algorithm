//https://leetcode.com/problems/valid-square/
#include<iostream>
#include<vector>
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

int getSquaredDistance(vector<int> &a, vector<int> &b) {
    int dx = a[0]-b[0];
    int dy = a[1]-b[1];
    return dx*dx + dy*dy;
}

bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    // connected, perpecular
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vector<int> dist_sq(6);
    dist_sq[0] = getSquaredDistance(p1, p2);
    dist_sq[1] = getSquaredDistance(p1, p3);
    dist_sq[2] = getSquaredDistance(p1, p4);
    dist_sq[3] = getSquaredDistance(p2, p3);
    dist_sq[4] = getSquaredDistance(p2, p4);
    dist_sq[5] = getSquaredDistance(p3, p4);
    sort(dist_sq.begin(), dist_sq.end());

    //For the Six Distances in Sorted Array
    //The 1st and the 4th distance should be equal (This implies first 4 are equal)
    //The 5th and the 6th distance should be equal
    //Side should not be zero/Distance of side and diagonal shouldn't be equal
    return (dist_sq[0]>0  // >0 for all
            && dist_sq[0]==dist_sq[3] // first 4 equal
            && dist_sq[4]==dist_sq[5] // longest 2 (diagnal) equal
            && dist_sq[3]<dist_sq[4]); // side < diagnal
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