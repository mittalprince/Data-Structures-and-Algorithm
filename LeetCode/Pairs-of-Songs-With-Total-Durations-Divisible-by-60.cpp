//https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
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

int numPairsDivisibleBy60(vector<int>& time) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[60]={0};
    for(int i: time){
        arr[(i%60)]++;
    }

    int ans=0;
    if(arr[0]){
        ans += arr[0]*(arr[0]-1)/2;
    }
    if(arr[30]){
        ans += arr[30]*(arr[30]-1)/2;
    }

    for(int i=1; i<30; i++){
        ans += (arr[i]*arr[60-i]);
    }

    return ans;
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