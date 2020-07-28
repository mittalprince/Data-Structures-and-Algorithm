#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int minFlips(int a, int b, int c) {
    int ans=0;

    for(int i=0; i<32; i++){
        int val = ((a>>i)&1);
        int val1 = ((b>>i)&1);
        int val2 = ((c>>i)&1);

        if(val2){
            if(!val && !val1) ans += 1;
        }
        else{
            ans += val+val1;
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}