#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int candy(vector<int>& ratings) {
    int n=ratings.size();

    vector<int>ans(n, 1);

    for(int i=1; i<n; i++){
        if(ratings[i] > ratings[i-1]){
            ans[i] = ans[i-1]+1;
        }
    }

    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1]){
            ans[i] = max(ans[i], ans[i+1]+1); 
        }
    }

    int total_req_candy=0;
    for(int i: ans){
        total_req_candy += i;
    }

    return total_req_candy;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}