#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX 100005

int main(){
    int n;
    cin>>n;
    ll arr[n][3];
    for(int i=0; i<n; i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    for(int i=1; i<n; i++){
        arr[i][0] += min(arr[i-1][1], arr[i-1][2]); 
        arr[i][1] += min(arr[i-1][0], arr[i-1][2]); 
        arr[i][2] += min(arr[i-1][0], arr[i-1][1]); 
    }
    
    cout<<min(arr[n-1][0], min(arr[n-1][1], arr[n-1][2]))<<endl;
    return 0;
}