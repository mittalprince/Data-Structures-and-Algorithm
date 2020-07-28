#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

/*
For a index, I want to find how many elements to its left are greater than it, continuously
Similarly to right
Then just a simple formula will do : (A[i]*t[i]*T[i])
*/

int sumSubarrayMins(vector<int>& A) {
    int n=A.size();
    if(n==0) return 0;

    stack<pair<int, int>>s;
    vector<int>t(n);

    for(int i=0; i<n; i++){
        int ct=0;
        while(!s.empty() && s.top().first>=A[i]){
            ct += s.top().second;
            s.pop();
        }
        if(s.empty()){
            t[i] = i+1;
        }
        else{
            t[i] = 1+ct;
        }

        s.push({A[i], t[i]});
    }

    while(!s.empty()) s.pop();

    vector<int>T(n);

    for(int i=n-1; i>=0; i--){
        int ct=0;
        while(!s.empty() && s.top().first>A[i]){
            ct += s.top().second;
            s.pop();
        }
        if(s.empty()){
            T[i] = n-i;
        }
        else{
            T[i] = 1+ct;
        }

        s.push({A[i], T[i]});
    }

    int ans=0;
    for(int i=0; i<n; i++){
        int a = (A[i]*t[i]*T[i])%mod;
        ans = (ans+a)%mod;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}