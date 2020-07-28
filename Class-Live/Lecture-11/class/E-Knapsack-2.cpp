#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005
#define inf 100000000000
// for a particular cell we want min capacity and max profit, as i can have profit of x with y cpacity why i take y+z capcity
// to pick a items we need  profit >= of this price (price<= profit)
// we are building table where we have n items and p amt of proift
// dp[i][j] -> what will be min cpacity i must have if i can pick i total itmes with p max profit

ll *weight, *price;
ll n, capacity;
ll dp[101][MAX];
// as we have total max 100 items and 10^5 max profit 

// dp[i][j] -> min capcity we require if we can pick from total i items and we must have j profit

// in this problem we map item with profit rather than item with capcity
// so in end we traverse last row and check all capcity that we fill in table which are less than bag capacity, this will gives max profir (which is nothing but j col val)

ll knapsack(ll max_profit){

    for(ll items=0; items<=n; items++){ 
        // so for total i items we will min cpacity if we have 0-max_profit profit
        for(ll profit=0; profit<=max_profit; profit++){
            if(items==0){
                if(profit==0) dp[items][profit]=0;// if we have 0 profit and 0 item, 0 will be our req capcity
                else dp[items][profit]=inf; // but if we have 0 item and need some profit then INF will be needed capcity(we take INF as we find ans using min)
            }
            else if(price[items-1]<=profit){
                // if we can we have 2 possibility
                // 1. don't pick, normal get min capcity with this given profit with total (item-1) elemnts
                // 2. if we pick, we check what will be min capcity req when we have total (item-1) elemnts and (profit-price[i-1]) total profit
                // so int this case min cap will be dp[items-1][profit-price[items-1]]+weight[items-1]
                dp[items][profit] = min(dp[items-1][profit-price[items-1]]+weight[items-1], dp[items-1][profit]);
            }
            else{
                // if we can't pick the ith item we will consider min cpacity for this profit without taking this item
                // that is dp[item-1][profit]
                dp[items][profit] = dp[items-1][profit];
            }
        }
    }

    ll ans=0;
    for(ll profit=0; profit<=max_profit; profit++){
        if(dp[n][profit]<=capacity) ans=profit;
    }

    return ans;
}

int main(){
    cin>>n>>capacity;
    weight = new ll[n];
    price = new ll[n];
    ll max_profit=0;
    for(int i=0; i<n; i++){
        cin>>weight[i]>>price[i];
        max_profit += price[i];
    }

    cout<<knapsack(max_profit)<<endl;
    return 0;
}