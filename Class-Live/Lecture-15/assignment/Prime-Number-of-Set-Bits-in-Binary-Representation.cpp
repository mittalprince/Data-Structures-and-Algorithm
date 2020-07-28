#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int countBits(int n){
    int ct=0;
    while(n){
        if(n&1) ct++;
        n >>=1;
    }
    return ct;
}

int countPrimeSetBits(int L, int R) {
    int ans=0;
    for(int i=L; i<=R; i++){
        int ct = countBits(i);
        if(ct==2||ct==3||ct==5||ct==7||ct==11||ct==13||ct==17||ct==19) ans++;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}