// https://leetcode.com/problems/number-of-squareful-arrays/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
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

void solve(vector<int>arr, int n, int start, int &ans){
    if(start>1){
        int number = sqrt(arr[start-1]+arr[start-2]);
        if(arr[start-1]+arr[start-2] != number*number){
            return;
        }
    }
    if(start==n){
        ans++;
        return;
    }

    for(int j=start; j<n; j++){
        if(j==start or arr[j]!=arr[start]){
            swap(arr[j], arr[start]);
            solve(arr, n, start+1, ans);
        }
    }
}

int numSquarefulPerms(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=A.size();
    int ans=0;

    sort(A.begin(), A.end());
    solve(A, n, 0, ans);
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