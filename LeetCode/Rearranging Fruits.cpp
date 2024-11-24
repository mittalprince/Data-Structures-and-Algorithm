// https://leetcode.com/problems/rearranging-fruits/
#include<iostream>
#include<vector>
#include<map>
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

long long minCost(vector<int>& basket1, vector<int>& basket2) {
    map<int, int>m;
    for(int i: basket1)m[i]++;
    for(int i: basket2)m[i]--;
    vector<long long>swaps;
    long long res = 0, small = begin(m)->first;
    for(auto it: m){
        if(it.second&1)return -1;
        for(int i=0; i<abs(it.second)/2; i++){
            swaps.push_back(it.first);
        }
    }
    for(int i=0; i<swaps.size()/2; i++){
        //there's a catch. Instead of swapping first and last element of vector, we can choose the minimum value of the baskets and use it twice to place the elements in their required position.
        res += min(swaps[i], 2*small);
    }
    return res;
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