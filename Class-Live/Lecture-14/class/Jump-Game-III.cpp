#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool solve(vector<int>&arr, int i){
    if(i>=arr.size() || i<0 || arr[i]<0) return false;

    if(arr[i] == 0) return true;
    arr[i] *= -1;
    return solve(arr, i+arr[i]) || solve(arr, i-arr[i]);
}

bool canReach(vector<int>& arr, int start) {
    return solve(arr, start-arr[start]) || solve(arr, start+arr[start]);    
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}