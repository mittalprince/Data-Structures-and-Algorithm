// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
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

int maximumCandies(vector<int>& candies, long long k) {
    int left = 0, right = 1e7;
    while (left < right) {
        long sum = 0, mid = (left + right + 1) / 2;
        for (int& a : candies) {
            sum += a / mid;
        }
        if (k > sum)
            right = mid - 1;
        else
            left = mid;
    }
    return left;
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