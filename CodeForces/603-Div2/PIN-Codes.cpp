// https://codeforces.com/contest/1263/problem/B
#include<iostream>
#include<vector>
#include<map>
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
    int n;
    cin>>n;

    map<string, int>m;
    vector<string>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
        m[arr[i]]++;
    }

    int ans=0;
    for(int i=0; i<n; i++){
        if(m[arr[i]]>1){
            m[arr[i]]--;
            for(int j=0; j<10; j++){
                arr[i][0] = '0'+j;
                if(m[arr[i]]==0){
                    ans++;
                    m[arr[i]]++;
                    break;
                }
            }
        }
    }
    cout<<ans<<endl;
    for(string i: arr){
        cout<<i<<endl;
    }
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