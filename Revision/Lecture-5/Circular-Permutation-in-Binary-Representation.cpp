// https://leetcode.com/problems/circular-permutation-in-binary-representation/
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

void reverse(vector<int>&arr, int s, int e){
    while(s<e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }    
}

vector<int> circularPermutation(int n, int start) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>arr;
    for(int i=0; i<pow(2,n); i++){
        int gc = i^(i>>1);
        arr.push_back(gc);
    }

    int k=0;
    for(k=0; k<arr.size(); k++){
        if(arr[k]==start)break;
    }

    k = arr.size()-k;
    reverse(arr, 0, arr.size()-1);
    reverse(arr, 0, k-1);
    reverse(arr, k, arr.size()-1);

    return arr;
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