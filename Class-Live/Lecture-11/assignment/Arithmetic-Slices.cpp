#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int numberOfArithmeticSlices(vector<int>& A) {
    int ans=0;
    vector<int>dp(A.size()+1, 0);

    for(int i=2; i<A.size(); i++){
        if(A[i]-A[i-1] == A[i-1]-A[i-2]){
            dp[i] = dp[i-1]+1;
        }
        else dp[i]=0; // 0 because, if this can't form arithmetic seq then all further seq include this no also not arthimetci as diff is not common 

        ans += dp[i];
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}