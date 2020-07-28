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

int n,c;

void solve(){
    ll arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(i>0)arr[i] += arr[i-1];
        arr[i] %= c;   
    }

    int visited[c];
    for(int i=0; i<c; i++){
        visited[i]=-1;
    }
    visited[0]=0;

    for(int i=0; i<n; i++){
        if(visited[arr[i]] != -1){
            int prev_idx = visited[arr[i]];
            if(arr[i]) prev_idx++;
            for(int k=prev_idx; k<=i; k++){
                cout<<k+1<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            visited[arr[i]]=i;
        }
    }

    cout<<"no sweets\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>c>>n;
    while(c and n){
        solve();
        cin>>c>>n;
    }
    return 0;
}