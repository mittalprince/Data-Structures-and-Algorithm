//https://leetcode.com/problems/increasing-triplet-subsequence/
#include<iostream>
#include<vector>
#include<climits>
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

bool increasingTriplet(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int first_min=INT_MAX, second_min=INT_MAX;
    for(int i: nums){
        if(i<=first_min){
            first_min=i;
        }
        else if(i<=second_min){
            second_min=i;
        }
        else return true;
    }
    return false;
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