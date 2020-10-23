// https://leetcode.com/problems/beautiful-array/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

vector<int> beautifulArray(int N) {
    vector<int>ans = {1};
    int temp;

    while(ans.size()<N){
        vector<int>temp_vec;

        for(int i: ans){
            temp = i*2-1;
            if(temp<=N)temp_vec.push_back(temp);
        }
        for(int i: ans){
            temp = 2*i;
            if(temp<=N)temp_vec.push_back(temp);
        }

        ans = temp_vec;
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