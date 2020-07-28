#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

//variation of LIS
int maxEnvelopes(vector<vector<int>>& e) {
    sort(e.begin(), e.end(), [](vector<int>a, vector<int>b)->bool{
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    });       

    int n = e.size();
    vector<int>dp(n, 1);

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(e[j][0]<e[i][0] && e[j][1]<e[i][1] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=0; i<n; i++){
        ans = max(dp[i], ans);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}