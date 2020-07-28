#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void squareFullArray(vector<int>arr, int n, int start, int& ct){
    if(start>1){
        int number = sqrt(arr[start-1]+arr[start-2]);
        if(arr[start-1]+arr[start-2] != number*number) return;
    }

    if(start == n){
        ct++;
        // return;
    }

    for(int j=start; j<n; j++){
        if(j==start || arr[j] != arr[start]){
            swap(arr[j], arr[start]);
            squareFullArray(arr, n, start+1, ct);
            // swap(arr[j], arr[start]);
        }
    }
}

int numSquarefulPerms(vector<int>&arr){
    int n=arr.size();
    int ct=0;
    sort(arr.begin(), arr.end());
    squareFullArray(arr, n, 0, ct);
    return ct;
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    int ans = numSquarefulPerms(arr);
    cout<<ans<<endl;
    return;
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}