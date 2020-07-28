 #include<iostream>
 #include<vector>
 using namespace std;
 typedef long long ll;
 #define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
 #define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
 #define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
 #define debug(x) cout<<x<<"\n";
 #define inf 1e9
 #define INF 1e16
 #define MOD 1000000007
 
 void solve(){
    string b;
    cin>>b;

    if(b.length() == 2){
        cout<<b<<endl;
        return;
    }

    string a="";
    a += b[0];
    for(int i=1; i<b.length(); i+=2){
        a += b[i];
    }
    cout<<a<<endl;
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