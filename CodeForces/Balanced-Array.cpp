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
        if((n/2)&1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            int arr[n];
            int ptr=2;
            ll sum=0;
            for(int i=0; i<(n/2); i++){
                arr[i]=ptr;
                ptr +=2;
                sum += arr[i];
            }
            ptr=1;
            for(int i=n/2; i<n-1; i++){
                arr[i]=ptr;
                ptr+=2;
                sum -=arr[i];
            }
            arr[n-1]=sum;

            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}