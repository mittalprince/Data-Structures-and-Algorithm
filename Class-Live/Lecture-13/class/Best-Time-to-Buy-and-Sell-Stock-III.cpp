#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
*/

int maxProfit(vector<int>& prices) {
    int n=prices.size();

    if(n<=1) return 0;

    int left[100005]={0}; //store profit from left, what will be max profit till ith stock(when i can make transaction one time)

    int right[100005]={0}; //store profit from right, what will will be max profit if i can sell from nth stock to ith stocks(when i can make transaction one time) 

    int min_till_now = prices[0];
    for(int i=1; i<n; i++){
        // left[i] will be max of either prev day profit or curr_day profit (that is if i can sell, so prices[i]-mim_stock_price_till_now)
        left[i] = max(left[i-1], prices[i]-min_till_now);
        min_till_now = min(min_till_now, prices[i]); // maintain min stock price
    }

    int max_till_now = prices[n-1];
    for(int i=n-2; i>=0; i--){
        // right[i] will be max day profit on i+1 day or (max_stock_price till now)-price of ith stack
        right[i] = max(right[i+1], max_till_now-prices[i]);
        max_till_now = max(max_till_now, prices[i]); // update max stock price 
    }

    // ans will be max of left[i]+right[i+1]
    int ans=-1;
    for(int i=0; i<n-1; i++){
        ans = max(ans, left[i]+right[i+1]);
    }

    ans = max(ans, max(left[n-1],right[0])); // here we check when i can purchase stock on first day and sell it on last day
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}