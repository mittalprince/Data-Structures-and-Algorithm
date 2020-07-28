// https://codeforces.com/contest/1038/problem/D
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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);

    if(n==1){
        cout<<arr[0];
        return 0;
    }
    int max_idx=-1;
    for(int i=0; i<n; i++){
        if(max_idx==-1 or arr[i]>arr[max_idx])max_idx=i;
    }
    int min_idx=-1;
    for(int i=0; i<n; i++){
        if(i!= max_idx and (min_idx==-1 or arr[i]<arr[min_idx]))min_idx=i;
    }

    ll sum=0;
    for(int i=0; i<n; i++){
        if(i!= max_idx and i!= min_idx) sum += abs(arr[i]);
    }
    sum += arr[max_idx];
    sum -= arr[min_idx];
    cout<<sum<<endl;
    return 0;
}