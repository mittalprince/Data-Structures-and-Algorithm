#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string reorganizeString(string S) {
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

        // cout<<t1.second<<" "<<t1.first<<endl;
        // cout<<t2.second<<" "<<t2.first<<endl;
        // cout<<endl;

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
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}