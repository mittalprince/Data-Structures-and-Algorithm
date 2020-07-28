#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> countBits(int n) {
    vector<int> v(n+1);
    int i;

    for(i=1;i<=n;i++){
        if(i%2==1) v[i]=v[i-1]+1;
        else v[i]=v[(i+1)/2];
    }

    return v;
}

vector<int> countBits(int num) {

    if(num==0){
        return {0};
    }
    vector<int>ans(num+1, 0);
    ans[1]=1;
    int prev_2;

    for(int i=2; i<=num; i++){
        if(!(i&(i-1))){
            prev_2=i;
            ans[i]=1;
        }
        else{
            ans[i] = ans[prev_2]+ans[i-prev_2];
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}