// https://codeforces.com/contest/1209/problem/B
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
    int n;
    cin>>n;
    string s;
    cin>>s;

    int opt1=0;
    for(char i: s){
        opt1 += i=='1';
    }

    int arr[n][2];
    for(int i=0; i<n; i++)cin>>arr[i][0]>>arr[i][1];
    vector<int>ct(n, 0);

    int opt2=0;
    for(int i=1; i<=500; i++){
        for(int j=0; j<n; j++){
            if(arr[j][1]+ct[j]*arr[j][0] == i){
                s[j] = s[j]=='0'?'1':'0';
                ct[j]++;
            }
        }
        opt2=0;
        for(char j:s){
            opt2 += j=='1';
        }
        opt1 = max(opt1, opt2);
    }

    cout<<opt1<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}