// https://codeforces.com/contest/911/problem/E
#include<iostream>
#include<vector>
#include<stack>
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

    stack<int>s;
    s.push(n+1);

    int ptr=1;
    int arr[n];
    for(int i=0; i<n; i++){
        if(i<k){
            cin>>arr[i];
        }
        else{
            arr[i] = s.top()-1;
        }
        s.push(arr[i]);
        while(!s.empty() and s.top()==ptr){
            s.pop();
            ptr++;
        }
    }
    if(!s.empty()){
        cout<<"-1\n";
        return;
    }
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
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