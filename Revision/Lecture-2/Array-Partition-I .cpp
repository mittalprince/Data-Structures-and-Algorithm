#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int arrayPairSum(vector<int>&arr){
    int n=arr.size();
    vector<int>freq(20001, 0);

    for(int i: arr){
        freq[i+10000]++;
    }

    int sum=0;
    int pick=0;
    for(int i=0; i<20001; i++){
        if(freq[i]){
            for(int j=0; j<freq[i]; j++){
                pick++;
                if(pick&1) sum += (i-10000);
            }
        }
    }
    return sum;
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