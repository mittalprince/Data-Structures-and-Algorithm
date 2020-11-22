//https://codeforces.com/contest/1451/problem/C
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

void solve(){
    int n,k;
    cin>>n>>k;
    
    string a,b;
    cin>>a>>b;

    int freqA[27]={0}, freqB[27]={0};
    for(int i=0; i<n; i++){
        freqA[a[i]-'a']++;
        freqB[b[i]-'a']++;
    }

    bool flag=true;
    for(int i=0; i<26; i++){
        if(freqA[i]<freqB[i]){
            flag=false;
            break;
        }
        else if(freqA[i]==freqB[i])continue;
        else{
            int diff = freqA[i]-freqB[i];
            if(diff%k){
                flag=false;
                break;
            }
            else freqA[i+1]+=diff;
        }
    }

    if(flag){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}