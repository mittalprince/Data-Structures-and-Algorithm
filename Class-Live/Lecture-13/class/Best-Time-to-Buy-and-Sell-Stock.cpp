#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/*
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.
*/

int maxProfit(vector<int>& prices) {
    int minP = INT_MAX;
    int maxProfit=0;
    for(int i=0; i<prices.size(); i++){
        minP = min(minP, prices[i]);
        maxProfit = max(maxProfit, prices[i]-minP);
    }
    return maxProfit;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}