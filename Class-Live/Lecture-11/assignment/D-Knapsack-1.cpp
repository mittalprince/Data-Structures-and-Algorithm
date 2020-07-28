#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

ll n, capacity;
ll price[105], weight[105];
ll dp[105][MAX];

ll solve(){
    memset(dp, 0, sizeof(dp));

    for(int item=0; item<=n; item++){
        for(int w=0; w<=capacity; w++){
            if(item == 0|| w==0){
                dp[item][w]=0;
            }
            else if(w>=weight[item-1]){
                dp[item][w] = max(price[item-1]+dp[item-1][w-weight[item-1]], dp[item-1][w]);
            }
            else dp[item][w] = dp[item-1][w];
        }
    }
    return dp[n][capacity];
}

int main(){
    cin>>n>>capacity;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>price[i];
    }
    cout<<solve()<<endl;
    return 0;
}