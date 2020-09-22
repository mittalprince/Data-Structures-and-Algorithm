// https://leetcode.com/problems/majority-element-ii/
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

vector<int> majorityElement(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f_cand, s_cand, ct1=0, ct2=0;

    int n=nums.size();

    for(int i:nums){
        if(i==f_cand)ct1++;
        else if(i==s_cand)ct2++;
        else if(ct1==0){
            ct1++;
            f_cand=i;
        }
        else if(ct2==0){
            ct2++;
            s_cand=i;
        }
        else{
            ct1--;
            ct2--;
        }
    }

    ct1=0, ct2=0;
    for(int i:nums){
        if(i==f_cand)ct1++;
        else if(i==s_cand)ct2++;
    }

    vector<int>ans;
    if(ct1>(n/3))ans.push_back(f_cand);
    if(ct2>(n/3))ans.push_back(s_cand);

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