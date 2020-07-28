// https://www.interviewbit.com/problems/set-matrix-zeros/
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

void setZeros(vector<vector<int> >&A){
    int n=A.size();
    int m=n?A[0].size():0;

    if(!n or !m)return;

    bool firstRowZero=false, firstColZero=false;

    for(int i=0; i<m; i++){
        if(A[0][i]==0){
            firstRowZero=true;
            break;
        }
    }

    for(int i=0; i<n; i++){
        if(A[i][0]==0){
            firstColZero=true;
            break;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(A[i][0]==0 or A[0][j]==0)A[i][j]=0;
        }
    }

    if(firstRowZero){
        for(int i=0; i<m; i++)A[0][i]=0;
    }
    if(firstColZero){
        for(int i=0; i<n; i++)A[i][0]=0;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}