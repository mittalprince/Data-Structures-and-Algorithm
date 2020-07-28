#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> twoSum(vector<int>& A, int target) {
    int s=0, e=A.size()-1;
    
    while(s<e){
        if(A[s]+A[e] == target){
            return {s+1, e+1};
        }
        else if(A[s]+A[e]<target){
            s++;
        }
        else e--;
    }
    return {};
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    ip(arr, n);
    int target;
    cin>>target;
    vector<int>res = twoSum(arr, target);
    for(int i: res) cout<<i<<" ";
    cout<<endl;
    return 0;
}