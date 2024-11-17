// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
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

int minimizedMaximum(int n, vector<int>& quantities) {
    int left = 1, right = 100000;
    while(left<right){
        int mid = left + (right-left)/2;
        int sum = 0;
        for(int a: quantities){
            sum += (a + mid-1)/mid; // ceil(a/mid);
        }
        if(sum>n) left = mid+1;
        else right=mid;
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