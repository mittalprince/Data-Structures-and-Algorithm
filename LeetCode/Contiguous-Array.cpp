#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int findMaxLength(vector<int>& nums) {
    int n=nums.size();

    map<int, int>m;
    m[0]=-1;
    int ans=0, ct=0;

    for(int i=0; i<n; i++){
        if(nums[i] == 1)ct++;
        else ct--;

        if(m.find(ct) != m.end()){
            ans = max(ans, i-m[ct]);
        }
        else m[ct]=i;
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