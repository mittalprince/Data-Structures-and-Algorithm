// https://codeforces.com/contest/599/problem/B
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
#define MAX 100005

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m;
    cin>>n>>m;
    
    int pos[MAX];
    vector<int>ct(MAX, 0);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        pos[x]=i+1;
        ct[x]++;
    }
    int flag=1, update=false;;
    int b[MAX];
    ip(b, m);

    for(int i=0; i<m; i++){
        int x = b[i];
        if(ct[x]==0){
            flag=0;
        }
        if(ct[x]>1 and flag){
            flag=-1;
        }
    }
    if(!flag){
        cout<<"Impossible\n";
        return 0;
    }
    else if(flag == -1){
        cout<<"Ambiguity\n";
        return 0;
    }
    else{
        cout<<"Possible\n";
        for(int i=0; i<m; i++){
            cout<<pos[b[i]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}