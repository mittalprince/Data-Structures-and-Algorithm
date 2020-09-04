// https://leetcode.com/problems/repeated-substring-pattern/
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

vector<int>lps;

void solve(string s){
    int i=1, j=0;
    int len=s.length();

    while(i<len){
        while(j>0 and s[i]!=s[j]){
            j = lps[j-1];
        }

        if(s[i]==s[j]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else if(j==0){
            lps[i]=0;
            i++;
        }
    }
}

bool repeatedSubstringPattern(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=s.length();
    lps = vector<int>(n, 0);

    solve(s);
    int len = lps[n-1];

    return (len>0 and n%(n-len)==0);
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