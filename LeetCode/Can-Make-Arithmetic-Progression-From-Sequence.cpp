// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
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

bool canMakeArithmeticProgression(vector<int>& arr) {
    int diff=-1;
    int n=arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-1; i++){
        int d = abs(arr[i+1]-arr[i]);
        if(diff == -1)diff=d;
        else if(diff != d)return false;
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