// https://leetcode.com/problems/car-pooling/
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

bool carPooling(vector<vector<int>>& trips, int capacity) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>timeStamps(1001, 0);

    for(vector<int>trip: trips){
        timeStamps[trip[1]] += trip[0];
        timeStamps[trip[2]] -= trip[0];
    }

    int c=0;

    for(int i: timeStamps){
        c += i;
        if(c>capacity)return false;
    }
    return true;
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