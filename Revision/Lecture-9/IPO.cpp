// https://leetcode.com/problems/ipo/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital){
    int n=Profits.size();
    if(n==0) return 0;

    vector<pair<int, int> >arr;
    for(int i=0; i<n; i++){
        arr.push_back({Capital[i],Profits[i]});
    }

    sort(arr.begin(), arr.end());
    int initial_capital = W;
    priority_queue<int>pq;
    int i=0;

    while(k--){
        while(i<n && arr[i].first <= initial_capital){
            pq.push(arr[i++].second);
        }

        if(!pq.empty()){
            initial_capital += pq.top();
            pq.pop();
        }
    }

    return initial_capital;
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