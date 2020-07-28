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
    int n;
    cin>>n;
    int odd=0, even=0;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(i&1){
            even += (x%2 == 0);
        }
        else{
            odd += (x&1);
        }
    }

    if(odd != even){
        cout<<"-1\n";
    }
    else{
        cout<<even<<endl;
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