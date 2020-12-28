//https://leetcode.com/problems/reach-a-number/
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

int reachNumber(int target) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    target = abs(target);

    int step=0;
    int sum=0;
    while(sum<target){
        step++;
        sum+=step;
    }

    while((sum-target)&1){
        step++;
        sum+=step;
    }
    return step;
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