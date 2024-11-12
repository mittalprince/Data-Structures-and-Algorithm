// https://leetcode.com/problems/prime-subtraction-operation/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

void PrimeSieve(vector<bool>&v, int n){
    v[0]=v[1] =false;
    for(int i=2; i*i<=n; i++){
        if(v[i]){
            for(int j=i*i; j<=n; j+=i){
                v[j] = false;
            }
        }
    }
}
bool primeSubOperation(vector<int>& nums) {
    vector<bool>v(1005, true);
    int n = nums.size();
    PrimeSieve(v, 1000);

    vector<int>prime;
    for(int i=2; i<=1000; i++){
        if(v[i])prime.push_back(i);
    }
    int sz = prime.size();

    int flag = 0;
    int prev = nums[n-1];
    for(int i=n-2; i>=0; i--){
        if(nums[i]<prev){
            prev = nums[i];
        } else{
            flag = 1;
            for(int j=0; j<sz && prime[j]<nums[i]; j++){
                if(nums[i]-prime[j] < prev){
                    prev = nums[i]-prime[j];
                    flag = 0;
                    break;
                }
            }
            if(flag) break; // we can't get desired config as nums[i]>nums[i+1]
        }
    }
    return !flag;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}