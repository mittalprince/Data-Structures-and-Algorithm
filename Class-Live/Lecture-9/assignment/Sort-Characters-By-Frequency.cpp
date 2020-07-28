#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string frequencySort(string s) {
    unordered_map<char, int>mp;
    for(char i: s){
        mp[i]++;
    }

    priority_queue<pair<int, char>>pq;

    for(auto it: mp){
        pq.push({it.second, it.first});
    }

    string ans="";
    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        while(top.first--){
            ans += top.second;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}