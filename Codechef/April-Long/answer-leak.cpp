#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define NMAX 505
#define KMAX 5005
int a[NMAX][KMAX];

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        for(int i=0; i<n; i++)
            for(int j=0; j<k; j++) a[i][j]=0;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < k; j++)
                    cin>>a[i][j];
                    // a[i][j] store ans of ith question for jth set 
        }
        for(int i = 0; i<n; i++){
            // use bructe force
            // find the jth col of each question 
            cout<<a[i][i/5]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}