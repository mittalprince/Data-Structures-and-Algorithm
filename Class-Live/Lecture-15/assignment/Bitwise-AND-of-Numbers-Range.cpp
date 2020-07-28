#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int rangeBitwiseAnd(int m, int n) {

    int count=0;
    while(m!=n){
        m=m>>1;
        n=n>>1;
        count++;
    }
    n=n<<count;
    return n;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}