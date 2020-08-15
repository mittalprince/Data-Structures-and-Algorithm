// https://hack.codingblocks.com/app/contests/1496/383/problem
#include<iostream>
#include<vector>
#include<bitset>
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
#define MAX 100

int ans=0, n;
bitset<MAX>cols, ld, rd;
bool arr[MAX][MAX];

void nQueen(int i){
    if(i==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]){
                    cout<<"{"<<(i+1)<<"-"<<(j+1)<<"} ";
                }
            }
        }
        ans++;
        return;
    }

    for(int j=0; j<n; j++){
        if(!cols[j] and !rd[i+j] and !ld[j-i+(n-1)]){
            cols[j]=rd[i+j]=ld[j-i+(n-1)]=1;
            arr[i][j]=true;
            nQueen(i+1);
            cols[j]=rd[i+j]=ld[j-i+(n-1)]=0;
            arr[i][j]=false;
        }
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n;
    nQueen(0);
    cout<<endl<<ans<<endl;
    
    return 0;
}