// https://codeforces.com/contest/525/problem/A
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
    string s;
    cin>>s;
    int freq[125]={0};
    int ans=0;
    for(int i=0; i<2*n-2; i++){
        if(i%2==0){
            freq[s[i]-32]++;
        }
        else{
            if(!freq[s[i]])ans++;
            else freq[s[i]]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}