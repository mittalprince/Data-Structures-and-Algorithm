// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
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

bool canPossible(vector<int>&arr, long long tastiness,int k){
    int ct=1, prev=arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]-prev >= tastiness){
            ct++;
            prev =arr[i];
            if(ct>=k)return true;
        }
    }
    return false;
}

int maximumTastiness(vector<int>& price, int k) {
    // https://leetcode.com/problems/maximum-tastiness-of-candy-basket/discuss/2948406/C%2B%2B-Aggresive-Cows-oror-Exact-Same-code-oror-BS-on-ans
    sort(price.begin(),price.end());
    int n=price.size();
    int s=1, e = price[n-1]-price[0];
    int ans=0;
    while(s<=e){
        long long mid =s+(e-s)/2;
        if(canPossible(price, mid, k)) {
            ans=mid;
            s = mid+1;
        }
        else e=mid-1;
    }
    return ans;
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