// https://leetcode.com/problems/distant-barcodes/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<int, int>m;
    for(int i: barcodes){
        m[i]++;
    }

    priority_queue<pair<int, int> >pq;
    for(auto it: m){
        pq.push({it.second, it.first});
    }

    vector<int>ans;
    while(pq.size()>=2){
        pair<int, int>a = pq.top(); pq.pop();
        pair<int, int>b = pq.top(); pq.pop();

        ans.push_back(a.second);
        ans.push_back(b.second);
        if(a.first>1){
            a.first--;
            pq.push(a);
        }
        if(b.first>1){
            b.first--;
            pq.push(b);
        }
    }

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }

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