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
        ll sum=1;
        for(int i=1; i<n; i++){
            sum += (1<<i);
            if(n%sum == 0){
                break;
            }
        }
        cout<<(n/sum)<<endl;
    }
    return 0;
}