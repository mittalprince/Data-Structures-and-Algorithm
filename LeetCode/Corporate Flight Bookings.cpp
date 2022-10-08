// https://leetcode.com/problems/corporate-flight-bookings/
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

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int>ans(n, 0);
    for(auto it:bookings){
        ans[it[0]-1]+=it[2];
        if(it[1]<n) ans[it[1]]-=it[2];
    }
    for(int i=1; i<n; i++){
        ans[i] += ans[i-1];
    }
    return ans;
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