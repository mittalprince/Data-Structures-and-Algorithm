#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    while(true){
        int n;
        cin>>n;
        if(n == -1){
            break;
        }
        ll arr[n];
        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
        }
        if(sum%n){
            cout<<"-1\n";
            continue;
        }
        else{
            ll ans = 0, temp=0;
            int mean = sum/n;
            for(int i=0; i<n; i++){
                arr[i] = arr[i]-mean;
                if(i>0) arr[i] += arr[i-1];
                ans = max(ans, abs(arr[i]));
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}