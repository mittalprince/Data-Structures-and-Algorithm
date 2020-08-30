// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
#include<iostream>
#include<vector>
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

int solve(vector<int>t){
    vector<int>neg;
    int n=t.size();
    for(int i=0; i<n; i++){
        if(t[i]<0)neg.push_back(i);
    }
    if(neg.size()%2==0)return n;
    return max(neg[neg.size()-1], n-neg[0]-1);
}

int getMaxLen(vector<int>& arr) {
    int n=arr.size();
    int ans=0;

    for(int i=0; i<n; i++){
        int j=i;

        vector<int>t;
        while(j<n and arr[j]){
            t.push_back(arr[j]);
            j++;
        }
        ans = max(ans, solve(t));
        i=j;
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