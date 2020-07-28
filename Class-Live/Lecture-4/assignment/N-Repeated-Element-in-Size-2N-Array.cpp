#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int repeatedNTimes(vector<int>&arr){
    int n=arr.size();
    for(int i=0; i<n-2; i++){
        if(arr[i]==arr[i+1]||arr[i]==arr[i+2]) return arr[i];
    }
    return arr[n-1];

    int cand=arr[0];
    int idx=-1, ct=0;
    for(int i=1; i<n; i++){
        if(arr[i] == cand) return arr[i];
        if(ct==0){
            idx=i;
        }
        ct += (arr[i]==arr[idx])?1:-1;
    }
    return arr[idx];
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    ip(arr, n);
    cout<<repeatedNTimes(arr)<<endl;
    return 0;
}