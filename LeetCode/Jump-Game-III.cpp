//https://leetcode.com/problems/jump-game-iii/
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

bool solve(vector<int>&arr, int i){
    if(i>=arr.size() || i<0 || arr[i]<0) return false;

    if(arr[i] == 0) return true;
    arr[i] *= -1;
    return solve(arr, i+arr[i]) || solve(arr, i-arr[i]);
}

bool canReach(vector<int>& arr, int start) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return solve(arr, start-arr[start]) || solve(arr, start+arr[start]);    
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