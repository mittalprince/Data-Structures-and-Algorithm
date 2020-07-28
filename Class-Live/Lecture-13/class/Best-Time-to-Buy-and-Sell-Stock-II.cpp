#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/* Logic
we maintain a prev price, whenver i got price lesser than prev, i.e here i can purchase.
so I add the curr profir to maxProfit and make currprofit to 0 and minP to iNT_MAX
second at each step i maintain my minP, for curr profit
and update curr profit at each step
*/
int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;

    int minP = INT_MAX;
    int max_profit = 0, curr_profit=0;
    int temp = prices[0];

    for(int i=0; i<prices.size(); i++){
        if(temp>prices[i]){
            max_profit += curr_profit;
            curr_profit=0;
            minP = INT_MAX;
        }
        if(minP > prices[i]){
            minP = prices[i];
        }

        curr_profit = max(curr_profit, prices[i]-minP);
        temp = prices[i];
    }

    max_profit += curr_profit;
    return max_profit;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}