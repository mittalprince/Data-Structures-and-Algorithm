// https://hack.codingblocks.com/app/contests/1496/1259/problem
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

void towerOfHanoi(int n, string src, string dest, string aux){
    if(n==1){
        cout<<"Move 1th disc from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1, src, aux, dest);
    cout<<"Move "<<n<<"th disc from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, aux, dest, src);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    towerOfHanoi(n, "T1", "T2", "T3");
    cout<<((1<<n)-1)<<endl;
    
    return 0;
}