// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
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

int minCost(string s, vector<int>& cost) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int total_cost=0;
    for(int i: cost){
        total_cost+=i;
    }

    char prev = (char)0;
    int mx=0, idx=0;


    for(char c: s){
        if(c != prev){
            total_cost -= mx;
            mx=0;
            prev = c;
        }
        mx = max(mx, cost[idx]);
        idx++;
    }

    total_cost-=mx;
    return total_cost;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}