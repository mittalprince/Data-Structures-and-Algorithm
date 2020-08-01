// https://codeforces.com/contest/433/problem/B
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);

    vector<ll>prefix(n, 0);
    prefix[0]=arr[0];
    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1]+arr[i];
    }

    sort(arr.begin(), arr.end());
    vector<ll>prefixSort(n, 0);
    prefixSort[0]=arr[0];
    for(int i=1; i<n; i++){
        prefixSort[i] += prefixSort[i-1]+arr[i];
    }

    int q;
    cin>>q;
    while(q--){
        int type,l,r;
        cin>>type;
        cin>>l>>r;
        l--;r--;
        if(type==1){
            cout<<(prefix[r]-((l>0)?prefix[l-1]:0))<<endl;
        }
        else{
            cout<<(prefixSort[r]-((l>0)?prefixSort[l-1]:0))<<endl;
        }
    }

    return 0;
}