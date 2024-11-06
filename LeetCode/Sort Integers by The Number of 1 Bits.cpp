// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
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

static bool comparator(int a, int b){
    int countA = __builtin_popcount(a);
    int countB = __builtin_popcount(b);
    if(countA == countB)return a<b;
    return countA < countB;
}
vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), comparator);
    return arr;
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