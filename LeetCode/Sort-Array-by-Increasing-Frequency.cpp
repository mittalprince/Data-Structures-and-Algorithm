//https://leetcode.com/problems/sort-array-by-increasing-frequency/
#include<iostream>
#include<vector>
#include<map>
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

vector<int> frequencySort(vector<int>& nums) {
    map<int, int>m;
    for(int i: nums){
        m[i]++;
    }

    vector<pair<int, int> >arr;
    for(auto it: m){
        arr.push_back({it.second, it.first});
    }

    sort(arr.begin(), arr.end(), [&](const pair<int, int>a, const pair<int,int>b){
       if(a.first==b.first){
           return a.second>b.second;
       } 
       return a.first<b.first; 
    });

    vector<int>ans;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].first; j++){
            ans.push_back(arr[i].second);
        }
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