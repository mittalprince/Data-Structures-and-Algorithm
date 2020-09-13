// https://www.geeksforgeeks.org/triplets-array-absolute-difference-less-k/
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

int lb(int val, vector<int>&arr, int n){
    int start=0, end=n-1, ans=-1;

    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]>=val){
            end=mid-1;
            ans=mid;
        }
        else start=mid+1;
    }
    return ans;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    ip(arr, n);

    sort(arr.begin(), arr.end());
    
    int ans=0;
    for(int i=2; i<n; i++){
        int curr = lb(arr[i]-k, arr, n);
        if(curr<=(i-2)){
            ans += ((i-curr)*(i-curr-1))/2;
        }
    }

    cout<<ans<<endl;
    return 0;
}