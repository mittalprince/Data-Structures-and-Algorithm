/*
Mosina and Mohit are very excited in watching IPL match of MI vs CSK. But problem is that Mosina is fan of MI and Mohit is fan of CSK.So Mohit uses his mind and asks Mosina that if she will give answer to his question then Mohit will support MI otherwise Mosina will have to suport CSK for 19 Sep 2020 match. Mohit's question is:-
As Monu is always interested in making money, so he decided to invest in some kind of precious pearls.But he is confused about when to buy and sell the pearl to get maximum profit. He decided to give this work to you, You have been given some future predictions of N days about the prices of the pearl in the form of an array A where the ith element denotes the price of the ith day. Also, there is a restriction on the number of pearls you can buy or sell. You can sell or buy at most K pearls.And initially you are having zero pearls.
You have to find the maximum profit that can be made by buying and selling the pearls
Note : You may not engage in multiple transactions at the same time

1<= N < 100000
0<= k< 100000
1<=Ai<= 100000

3 2
2 4 1

2
*/

// https://hack.codingblocks.com/app/contests/1783/1735/problem
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int solve(int k, vector<ll>&arr){
    int n=arr.size();
    if(n<=1)return 0;

    if(k>=(n/2)){
        ll ans=0;
        for(int i=1; i<n; i++){
            if(arr[i]>arr[i-1]){
                ans += arr[i]-arr[i-1];
            }
        }
        return ans;
    }

    ll dp[1001][1001]={0};
    for(int i=1; i<=k; i++){
        for(int j=1; j<n; j++){
            ll ans=0;

            for(int l=0; l<j; l++){
                if(arr[j]>arr[l]){
                    ans = max(ans, arr[j]-arr[l]+dp[i-1][l]);
                }
            }
            dp[i][j] = max(ans, dp[i][j-1]);
        }
    }
    return dp[k][n-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<ll>arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<solve(k,arr)<<endl;
}
