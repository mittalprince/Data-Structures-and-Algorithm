// https://www.interviewbit.com/problems/spiral-order-matrix-ii/
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

vector<vector<int> > generateMatrix(int A) {
    int n=A;
    int m=n;
    int i, r=0, c=0;
    vector<vector<int> > ans(A, vector<int>(A, 0));
    int val=1;
    
    while(r<n and c<m){
        for(int i=c; i<m; i++){
            ans[r][i]=val++;
        }
        r++;

        for(int i=r; i<n; i++){
            ans[i][m-1]=val++;
        }
        m--;

        if(c<m){
            for(int i=m-1; i>=c; i--){
                ans[n-1][i]=val++;
            }
            n--;
        }
        if(r<n){
            for(i=n-1; i>=r; i--){
                ans[i][c]=val++;
            }
            c++;
        }
    }
    return ans;
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