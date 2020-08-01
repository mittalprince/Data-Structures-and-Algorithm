// https://codeforces.com/contest/385/problem/C
    #include<iostream>
#include<vector>
#include<cstring>
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
#define MAX 10000005

bool isPrime[MAX];
ll divisibleNumbers[MAX];
int freq[MAX]={0};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fstIO;
    
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int x; cin>>x;
        freq[x]++;
    }

    memset(isPrime, 1, sizeof(isPrime));

    for(int i=2; i<MAX; i++){
        if(isPrime[i]){
            for(int j=i; j<MAX; j+=i){
                isPrime[j]=false;
                divisibleNumbers[i] += freq[j];
            }
        }
        divisibleNumbers[i] += divisibleNumbers[i-1];
    }
    
    ll q;
    cin>>q;
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(l>=MAX) l=MAX-1;
        if(r>=MAX) r=MAX-1;
        cout<<divisibleNumbers[r]-divisibleNumbers[l-1]<<endl;
    }
    return 0;
}