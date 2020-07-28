// https://codeforces.com/contest/1375/problem/B
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
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==0 or i==n-1){
                if(j==0 or j==m-1){
                    if(arr[i][j]>2){
                        cout<<"NO\n";
                        return;
                    }
                    arr[i][j]=2;
                }
                else{
                    if(arr[i][j]>3){
                        cout<<"NO\n";
                        return;
                    }
                    arr[i][j]=3;
                }
            }
            else if(j==0 or j==m-1){
                if(i==0 or i==n-1){
                    if(arr[i][j]>2){
                        cout<<"NO\n";
                        return;
                    }
                    arr[i][j]=2;
                }
                else{
                    if(arr[i][j]>3){
                        cout<<"NO\n";
                        return;
                    }
                    arr[i][j]=3;
                }
            }
            else{
                if(arr[i][j]>4){
                    cout<<"NO\n";
                    return;
                }
                arr[i][j]=4;
            }
        }
    }

    cout<<"YES\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
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