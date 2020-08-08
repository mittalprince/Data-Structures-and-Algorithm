// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
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

int minInsertions(string s) {
    int res=0, k=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='('){
            k++;
        }
        else{
            k--;
            if(i+1<s.length() and s[i+1]==')'){
                i++;
            }
            else res++;
        }
        if(k<0){
            k++;
            res++;
        }
    }
    return res+(2*k);
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