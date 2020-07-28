// https://www.interviewbit.com/problems/counting-triangles/
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

const int mod = 1000000007;

int nTriang(vector<int> &A) {
    int n = A.size();
    int ans=0;
    
    sort(A.begin(), A.end());
    for(int i=0; i<n-2; i++){
        int j=i+1;
        int k=n-1;
        
        while(j<k){
            if(A[i]+A[j]>A[k]){
                ans += (k-j);
                ans %= mod;
                j++;
            }
            else k--;
        }
    }
    ans %= mod;
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