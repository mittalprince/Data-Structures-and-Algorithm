#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int findLeastNumOfUniqueInts(vector<int>&arr, int k){
    unordered_map<int, int>m;
    for(int i: arr){
        m[i]++;
    }

    vector<pair<int, int> >t;
    for(auto it: m){
        t.push_back({it.second, it.first});
    }

    sort(t.rbegin(), t.rend());

    int i=0;
    while(i<k){
        int j=t.back().first;
        if(i+j<=k)t.pop_back();
        else break;
        i += j;
    }
    return t.size();
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