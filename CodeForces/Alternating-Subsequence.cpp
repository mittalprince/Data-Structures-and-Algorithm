#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool sameSign(int num1, int num2){
    if (num1 > 0 && num2 < 0)
        return false;
    if (num1 < 0 && num2 > 0)
        return false;
    return true;
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);
    ll sum=0;
    int curr=INT_MIN;
    int i=0;

    for(int i=0; i<n;){
        curr = arr[i];
        int j=i;
        while(j<n && sameSign(arr[i], arr[j])){
            curr = max(curr, arr[j]);
            j++;
        }
        sum += curr;
        i = j;
    }
    cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}