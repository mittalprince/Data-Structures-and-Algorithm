#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int findComplement(int num) {
    int ans=0;
    int i=0;

    while(num>0){
        if(!(num&1)){
            ans += (1<<i);
        }
        num >>= 1;
        i++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    cout<<findComplement(n)<<endl;
    return 0;
}