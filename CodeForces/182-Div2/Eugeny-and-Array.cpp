// https://codeforces.com/contest/302/problem/A
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

int main(){
    fstIO;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    int pos=0, neg=0;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x<0)neg++;
        else pos++;
    }

    for(int i=0; i<m; i++){
        int l,r;
        cin>>l>>r;
        int diff = (r-l+1);
        if(diff&1){
            cout<<"0\n";
        }
        else{
            if(((diff/2)<=pos) and ((diff/2)<=neg)){
                cout<<"1\n";
            }
            else cout<<"0\n";
        }
    }
    return 0;
}