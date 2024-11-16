// https://leetcode.com/problems/koko-eating-bananas/
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

bool canPlace(vector<int>& piles, int k, int h){
    int ans=0;
    for(int i: piles){
        ans += ceil((double)i/k);
    }
    return ans <= h;
}
int minEatingSpeed(vector<int>& piles, int h){
    sort(piles.begin(), piles.end());
    int n = piles.size();
    int l=1;
    int r=piles[n-1];

    while(l<r){
        int mid = (l+r)/2;
        if(canPlace(piles, mid, h)){
            r=mid;
        } else l=mid+1;
    }
    return l;
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