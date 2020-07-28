#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> countBits(int num) {
    if(num<=0){
        return {0};
    }
    vector<int>dp(num+1, 1);
    dp[0]=0;
    for(int i=3; i<=num; i++){
        dp[i] = dp[(i/2)]+(i&1);
    }
    return dp;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}