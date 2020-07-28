#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> prefix(n, 0);
    int q;
    cin>>q;
    while(q--){
        int l,r,d;
        cin>>l>>r>>d;
        prefix[l]+= d;
        if(r<n-1) prefix[r+1]-= d;
    }
    for(int i=1; i<n; i++){
        prefix[i] += prefix[i-1];
    }
    for(int i=0; i<n; i++){
        cout<<prefix[i]+arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}