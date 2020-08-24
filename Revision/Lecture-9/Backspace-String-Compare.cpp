// https://leetcode.com/problems/backspace-string-compare/
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

bool backspaceCompare(string s, string t) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i=s.length()-1, j=t.length()-1;
    int skips=0, skipt=0;

    while(i>=0 or j>=0){
        while(i>=0){
            if(s[i]=='#'){
                skips++;
                i--;
            }
            else if(skips>0){
                skips--;
                i--;
            }
            else break;
        }
        while(j>=0){
            if(t[j]=='#'){
                skipt++;
                j--;
            }
            else if(skipt>0){
                skipt--;
                j--;
            }
            else break;
        }

        if(i>=0 and j>=0 and s[i]!=t[j])return false;
        if((i>=0 and j<0) or (j>=0 and i<0))return false;

        i--; j--;
    }
    return true;
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