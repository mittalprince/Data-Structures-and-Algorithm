#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    ip(arr, n);

    int dp[k+1];
    for(int i=0; i<=k; i++) dp[i]=2;
    //dp[i] -> agr i stone remove karna hai toh jo phela chalega(1) voh jeetga ya dusara vala(2)
    // hence dp[i] -> ki val either 1/2


    for(int i=1; i<=k; i++){
        for(int j=0; j<n; j++){
            if(i-arr[j] < 0) continue;
            
            // check if current k mein se arr[i] hta de toh jitna stone bachenge 
            // that is dp[i-arr[i]], agr iski val 2 hai toh jo iss state par pheli bar aeyga voh harega and second jeetage
            // qki dono optimially khel rahe hai toh first chaheyga ki voh second person ko aise state par beja
            // jha second win hota hoo taki first win kar sake
            if(dp[i-arr[j]]==2){
                dp[i]=1;
            }
        }
    }
    if(dp[k] == 2) cout<<"Second\n";
    else cout<<"First\n";
    return 0;
}