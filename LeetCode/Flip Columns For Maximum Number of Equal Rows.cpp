// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/
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

int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
    unordered_map<string,int> hmap;
    for(auto x: matrix){
        string s=""; 
        //s keeps track of relative ordering of elements in a row w.r.t the first element
        int top=x[0];
        for(int i=0;i<x.size();i++){
            if(x[i]==top)
                s+='1';
            else
                s+='0';
        }
        hmap[s]++; 
    }

    int result=0;
    for(auto &[key,val]:hmap)
        result=max(result,val); 
    //rows that have identical relative ordering, can be simultaneously toggled columnwise in order to make all
    //elements of any of those rows unique. So the answer is maximum number of rows with identical relative ordering.
    return result;
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