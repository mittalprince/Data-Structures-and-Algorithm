// https://leetcode.com/problems/super-ugly-number/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
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

int nthSuperUglyNumber(int n, vector<int>& primes) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto cmp = [](const pair<int, int>a, const pair<int, int>b){
        return a.first>b.first;
    };
    priority_queue<pair<int,int>, vector<pair<int, int> >, decltype(cmp)>pq(cmp);
    int sz = primes.size();

    for (int i=0; i<sz; i++)
        pq.push(make_pair(primes[i], i));

    vector<int>index(sz, 0);
    vector<int>ans(n);
    ans[0]=1;
    int k=1;

    while(k<n){
        ans[k] = pq.top().first;
        while(!pq.empty() and pq.top().first == ans[k]){
            pair<int, int>top = pq.top();
            pq.pop();
            index[top.second]++;
            top.first = primes[top.second]*ans[index[top.second]];
            pq.push(top);
        }
        k++;
    }
    return ans[n-1];
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