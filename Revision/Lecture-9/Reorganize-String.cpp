// https://leetcode.com/problems/reorganize-string/
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

string reorganizeString(string S) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char, int>m;
    int n=S.length();

    for(char i: S){
        m[i]++;
        if(m[i]>((n+1)/2)) return "";
    }

    priority_queue<pair<int, char>>pq;

    for(auto it: m){
        pq.push({it.second, it.first});
    }

    string ans="";

    while(pq.size()>=2){
        auto t1=pq.top(); pq.pop();
        auto t2=pq.top(); pq.pop();

        ans += t1.second;
        ans += t2.second;

        if(t1.first>1) pq.push({t1.first-1, t1.second});
        if(t2.first>1) pq.push({t2.first-1, t2.second});
    }

    if(!pq.empty()){
        if(!ans.empty() && ans.back() == pq.top().second) return "";
        else ans += pq.top().second;
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