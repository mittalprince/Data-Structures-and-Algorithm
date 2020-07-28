#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n&1) n++;
        cout<<(n/2)-1<<endl;
    }
    return 0;
}