#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> sortByBits(vector<int>& arr) {
        
    sort(arr.begin(), arr.end(), [](int a, int b){
        int A = bitset<32>(a).count();
        int B = bitset<32>(b).count();
        
        return (A==B)? a<b:A<B;
    });
    
    return arr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}