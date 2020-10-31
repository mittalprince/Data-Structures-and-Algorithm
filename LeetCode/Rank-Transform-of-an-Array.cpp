// https://leetcode.com/problems/rank-transform-of-an-array/
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

vector<int> arrayRankTransform(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=arr.size();
    if(n==0)return {};

    int mx = *max_element(arr.begin(), arr.end());
    int mi = *min_element(arr.begin(), arr.end());

    vector<int>freq(mx-mi+1);
    for(int i: arr){
        freq[i-mi]=1;
    }

    int ct=0;
    for(int &i: freq){
        if(i){
            i=++ct;
        }
    }

    for(int &i:arr){
        i = freq[i-mi];
    }
    return arr;
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