#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int prime[11] = {2,3,5,7,11,13,17,19,23,29,31};

void solve(){
    int n,temp;
    int freq[11]={0};
    int total_colors=0;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>temp;
        for(int j=0; prime[j]*prime[j]<=temp; j++){
            if(temp%prime[j] == 0){
                if(!freq[j]){
                    total_colors++;
                    freq[j] = total_colors;
                }
                arr[i] = freq[j];
                // as we have already got a prime factor, so we dont need to check after it, so break
                // otherwise it gives Floating point exception: 8
                break;
            }
        }
    }
    cout<<total_colors<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}