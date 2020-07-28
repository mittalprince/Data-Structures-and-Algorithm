#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

int partitionDisjoint(vector<int>& arr) {
    int n=arr.size();
    int left_max=arr[0], curr_max=arr[0], len=0;    
    
    for(int i=1; i<n; i++){
        curr_max = max(curr_max, arr[i]);
        if(arr[i]<left_max){
            len=i;
            left_max = curr_max;
        }
    }
    
    return len+1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}