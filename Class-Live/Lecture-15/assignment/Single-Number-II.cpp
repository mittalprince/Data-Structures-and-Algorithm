#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int singleNumber(vector<int>& nums) {
    int ans=0;

    for(int i=0; i<32; i++){
        int n=0;
        for(int j: nums){
            n += (j>>i)&1;
        }
        if(n%3){
            ans |= (1<<i);
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