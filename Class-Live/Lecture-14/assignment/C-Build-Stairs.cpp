#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool check(int n, int arr[]){
    if(n==1) return true;
    
    arr[0]--;
    for(int i=0; i<n-1; i++){
        if(arr[i] == arr[i+1]) continue;
        if(arr[i] < arr[i+1]){
            arr[i+1]--;
        }
        else return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);

    (check(n, arr))?cout<<"Yes\n":cout<<"No\n";
    return 0;
}