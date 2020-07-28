// Flood fill Algorithm

// Flood fill
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007
#define MAX 105

int arr[MAX][MAX];

void solve(int n, int m, int x, int y, int newColor, int prevColor){
    if(x<0||y<0||x>=n||y>=m||arr[x][y] != prevColor){
        return;
    }

    arr[x][y]=newColor;
    solve(n,m,x+1,y,newColor,prevColor);
    solve(n,m,x-1,y,newColor,prevColor);
    solve(n,m,x,y+1,newColor,prevColor);
    solve(n,m,x,y-1,newColor,prevColor);
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>arr[i][j];
            }
        }
        
        int x,y,k;
        cin>>x>>y>>k;

        if(k != arr[x][y])
            solve(n,m,x,y,k,arr[x][y]);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}