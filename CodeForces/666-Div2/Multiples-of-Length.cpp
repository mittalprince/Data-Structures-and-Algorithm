// https://codeforces.com/contest/1397/problem/C
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
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ip(arr, n);

    if(n==1){
        cout<<"1 1\n"<<-arr[0]<<endl;
        cout<<"1 1 \n0\n";
        cout<<"1 1 \n0\n";
        return;
    }

    cout<<"1 1\n"<<-arr[0]<<endl; // make first element zero
    cout<<"2 "<<n<<endl; // then choose seg 2 to n and make all arr[i] a multiple of n
    arr[0]=0;

    for(ll i=1; i<n; i++){
        /*
        arr[i]%n -> yeh bateyga ki arr[i] mein kitna subtract kare ki yeh n ka multiple ban jaye, say x
        then hum x*(n-1) val ko arr[i] mein add kar denge jissi voh n ka multiple ban jayega
        Ex arr[i]=16, len=7 16%7->2 means 2 subtract karna hai,
        but agr hum (n-1) ko 2 times add kar de toh voh n ka pure mutiple hoga 16+(6+6)->28
        as jab hum n-1 ko add kar rhae hai 2 time and 2 already extra hai toh overall voh n ka hi multiple hoga
        */
        cout<<(arr[i]%n)*(n-1)<<" ";
        arr[i] += (arr[i]%n)*(n-1);
    }
    cout<<endl;
    cout<<"1 "<<n<<endl;
    for(ll i=0; i<n; i++){
        cout<<-arr[i]<<" ";
    }
    cout<<endl;
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