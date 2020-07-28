#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

vector<int> findDuplicates(vector<int>arr){
int n=arr.size();
    vector<int>ans;

    for(int i=0; i<n; i++){
        int idx = abs(arr[i])-1;
        if(arr[idx]<0) ans.push_back(abs(arr[i]));
        else arr[idx] *= -1;
    }
    return ans;
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