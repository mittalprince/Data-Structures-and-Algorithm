//https://leetcode.com/problems/stone-game-vi/
#include<iostream>
#include<vector>
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

int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> combined;
    int n = aliceValues.size();

    for (int i = 0; i < n; i++) {
        combined.push_back({aliceValues[i]+bobValues[i], i});
    }

    sort(combined.begin(), combined.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    });

    int a , b;
    a = b = 0;

    for (int i = 0; i < n; i++) {
        if(i&1) {
            b += bobValues[combined[i].second];
        }
        else{
            a += aliceValues[combined[i].second];
        }
    }

    return (a > b) ? 1 : (a == b) ? 0 : -1;        
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