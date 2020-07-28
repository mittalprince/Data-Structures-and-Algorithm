// phi1toN.cpp
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 10005

ll arr[MAX]={0}, prefix[MAX]={0};

// N(log(logN))
void solve(){
    for(int i=2; i<MAX; i++){
        arr[i] = i;
    }    
    arr[1]=1;
    for(int i=2; i<MAX; i++){
        if(arr[i]==i){
            for(int j=i; j<MAX; j+=i){
                arr[j] -= arr[j]/i;
            }
        }
    }
    prefix[1]=1;
    for(int i=2; i<MAX; i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    solve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=prefix[n];
        cout<<(ans*ans)<<endl;
    }
    return 0;
}
