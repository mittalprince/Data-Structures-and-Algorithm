// https://www.interviewbit.com/problems/max-distance/
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

int maximumGap(const vector<int> &A) {
    int n=A.size();
    int l[n], r[n];
    l[0]=A[0];
    
    for(int i=1; i<n; i++){
        l[i] = min(A[i], l[i-1]);
    }
    r[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--){
        r[i] = max(A[i], r[i+1]);
    }
    
    int ans=0;
    int i=0, j=0;

    while(i<n and j<n){
        if(l[i]<=r[j]){
            ans = max(ans, j-i);
            j++;
        }
        else i++;
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