// https://leetcode.com/problems/k-th-smallest-prime-fraction/
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

vector<int> kthSmallestPrimeFraction(vector<int>& A, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    auto compare = [&](pair<int, int>&a, pair<int, int>&b){
        return A[a.first]*A[b.second]>A[b.first]*A[a.second];
    };

    priority_queue<pair<int, int> ,vector<pair<int, int>>, decltype(compare)>pq(compare);

    int n=A.size();
    for(int i=0; i<n; i++){
        pq.push({i, n-1});
    }

    k--;
    while(k--){
        auto top = pq.top();
        pq.pop();
        if(top.second>0){
            pq.push({top.first, top.second-1});
        }
    }

    vector<int>ans;
    ans.push_back(A[pq.top().first]);
    ans.push_back(A[pq.top().second]);

    return ans;
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