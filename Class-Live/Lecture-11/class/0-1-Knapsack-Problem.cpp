#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1001

int n,W, p[MAX], wt[MAX];
int dp[MAX][MAX];

void solve(){
    cin>>n>>W;
    for(int i=0; i<n; i++){
        cin>>p[i];
    }
    for(int i=0; i<n; i++){
        cin>>wt[i];
    }
    memset(dp, 0, sizeof(dp));
    // dp[i][j] denotes with i can take total i items and have a capcity of w, what will be my max profit
    // dp[i][j] = max profit with total i item and w capacity

    // in knapsack we simply check two possiblity
    // 1. what will be max profit if I take ith item
    // 2. what will be max profit without this ith item

    for(int i=0; i<=n; i++){
        // so for toal i item we will max profit if we have 0-W capcity
        for(int w=0; w<=W; w++){
            if(i==0||w==0){
                dp[i][w]=0; //if we dont have any item or capcity then max profit will be 0
            }
            else if(wt[i-1]<=w){// if we can pick ith item (means its wt is less than bag capacity)
                dp[i][w] = max(p[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
                // we have two option either pick it or not
                // dp[i-1][w] denotes we wil not pick this and see max prfot without this, that is dp[i-1][w] (if we have to take onlye i-1 total items)
                /*
                dp[i-1][w-wt[i-1]]+p[i-1]
                means we take this item, so we will check what's max profit with (i-1) total item (as we include it so total will i-1+1= i itme)
                and (w-wt[i-1]) bag capacity, since if we take we have to adjust wt[i] in the same bag, so we check at (w-wt[i]) bag capcity
                and since at last we take this item we icnclude this item profit 
                */
            }
            else{
                // means we dont have enough bag capacity to pick this ith item, so we just consider profit with (i-1) total items
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    cout<<dp[n][W]<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}