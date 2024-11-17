// https://leetcode.com/problems/fruit-into-baskets/
#include<iostream>
#include<vector>
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

int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mpp;

    int i = 0, j = 0, res = 0;

    while(j < fruits.size()){
        mpp[fruits[j]]++;
        if(mpp.size() <= 2) res = max(res, j-i+1);
        else{
            mpp[fruits[i]]--;
            if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
            i++;
        }
        j++;
    }

    return res; 
}
int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}