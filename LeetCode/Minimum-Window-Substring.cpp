 // https://leetcode.com/problems/minimum-window-substring/
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

string minWindow(string s, string t){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ls=s.length();
    int lt=t.length();

    if(ls<lt)return "";

    int ms[256]={0}, mt[256]={0};
    for(char i: t){
        mt[i-32]++;
    }

    int start=0, start_idx=-1, min_len=INT_MAX, ct=0;

    for(int i=0; i<ls; i++){
        ms[s[i]-32]++;

        if(mt[s[i]-32]>0 and ms[s[i]-32]<=mt[s[i]-32])ct++;

        if(ct==lt){

            while(ms[s[start]-32]>mt[s[start]-32] or mt[s[start]-32]==0){
                if(ms[s[start]-32]>mt[s[start]-32]){
                    ms[s[start]-32]--;
                }
                start++;
            }

            int len = i-start+1;
            if(min_len>len){
                min_len=len;
                start_idx=start;
            }
        }
    }
    if(start_idx==-1)return "";
    return s.substr(start_idx, min_len);
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