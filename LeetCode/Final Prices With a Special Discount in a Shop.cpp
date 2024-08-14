// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

vector<int> finalPrices(vector<int>& prices) {
    int n=prices.size();

    vector<int>ans(n, 0);
    for(int  i=0; i<n; i++){
        int val = prices[i];
        for(int j=i+1; j<n; j++){
            if(prices[j]<=val){
                val -= prices[j];
                break;
            }
        }
        ans[i] = val;
    }
    return ans;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}