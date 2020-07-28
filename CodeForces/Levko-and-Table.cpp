#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cout<<k<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}