#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n;
    cin>>n;
    int arr[n];
    int freq[3]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
        arr[i] %= 3;
        freq[arr[i]]++;
    }
    int ans= (freq[0]/2) + min(freq[1], freq[2]);    
    cout<<ans<<endl;
    return 0;
}