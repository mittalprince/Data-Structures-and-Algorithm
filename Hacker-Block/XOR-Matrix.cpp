#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
#define MAX 505

int n, arr[MAX][MAX], c[MAX], i, j, m, xor_val;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
        xor_val ^=arr[i][0];
        c[i]=1;
    }

    if(!xor_val){
        for(i=0; i<n; i++){
            for(j=1; j<m; j++){
                if(arr[i][j]!=arr[i][0]){
                    c[i]=j+1; 
                    j=m; 
                    i=n; 
                    xor_val=1;
                }
            }
        }
    }

    if(!xor_val){
        cout<<"NIE";
        return 0;
    }
    cout<<"TAK\n";
    for(i=0;i<n;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}