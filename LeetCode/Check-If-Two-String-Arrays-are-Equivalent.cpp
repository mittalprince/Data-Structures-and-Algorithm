//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
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

bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a="", b="";
    for(string i: word1){
        a+=i;
    }
    for(string i: word2){
        b+=i;
    }

    return a==b;
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