#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int dp[105][10005];
    
int eggDrop(int n, int k){
    if(k<=1) return k; // when 0/1 building so total min attempt will be k
    if(n==1) return k; // when no of eggs 1, then min attempt will be k, as we try each building

    if(dp[n][k] != -1) return dp[n][k];
    int l=1, r=k, ans=k;

    // 2 possibility whether egg break or not
    // 1. if break we try lowerr floors, so total egg will be now n-1(one break) and rem floor will be x-1(as i drop form x, so try lower that is x-1)
    // 2. if not break then try higher floor, egg remain same(as not break), and fllor will be k-x(total k floor, drop from x, but not break, so looking upper of x, so total floor will be k-x).

    // now we take max of these two option, as conisder worst case possibility, as we dont the exact floor where egg break, we just find if we
    // we drop from this floor with n egg available what will be min attempts, so consider worst case as best case already covered with worst case

    // here we use BS, to find the optimal val of mid
    while(l<r){
        int mid = (l+r)/2;
        int left = eggDrop(n-1, mid-1);
        int right = eggDrop(n, k-mid);
        
        ans = min(ans, max(left, right)+1);
        
        if(left == right) break;
        if(left<right) l=mid+1;
        else r=mid;
    }
    
    return dp[n][k] = ans;
}

// recusive
int superEggDrop(int K, int N) {
    memset(dp, -1, sizeof(dp));
    return eggDrop(K, N);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}