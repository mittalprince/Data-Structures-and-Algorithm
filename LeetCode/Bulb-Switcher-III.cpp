#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int numTimesAllBlue(vector<int>& A) {
    int n=A.size();
    int mx = 0, ans=0;

    for(int i=0; i<n; i++){
        mx = max(mx, A[i]);
        // here we check, if we have traversed 5 elemnt and
        // 5 is max till now so all we have travered are less than 5
        // and since total traverse elemnt is 5, means all prev bulbs
        // light up already
        if(mx == i+1){
            ans++;
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