//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
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

int shipWithinDays(vector<int>& weights, int days) {
    int left = 0;
    int right = 0;
    for(int i : weights){
        left = max(left, i);
        right += i;
    }
    int mid;
    int ans = right;
    while(left <= right){
        mid = (left + right) / 2;
        if(check(weights, days, mid)){
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

bool check(vector<int>& weights, int days, int capacity){
    int requiredDays = 1;
    int currWeight = 0;
    for(int i : weights){
        if(currWeight + i > capacity){
            requiredDays++;
            currWeight = 0;
        }
        currWeight += i;
    }
    if(requiredDays > days) return false;
    return true;
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