//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
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

int longestSubstring(string s, int k) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans=0;
    int n=s.length();

    for(int h=1; h<=26; h++){
        int i=0,j=0;
        int freq[26]={0};
        int unique=0, notLessthanK=0;

        while(j<n){
            if(unique<=h){
                int idx=s[j]-'a';
                if(freq[idx]==0)unique++;
                freq[idx]++;

                notLessthanK += (freq[idx]==k);
                j++;
            }
            else{
                int idx=s[i]-'a';
                notLessthanK -= (freq[idx]==k);

                freq[idx]--;
                if(freq[idx]==0)unique--;
                i++;   
            }

            if(unique==h and notLessthanK==h){
                ans = max(ans, j-i);
            }
        }
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