//https://leetcode.com/problems/count-the-number-of-consistent-strings/
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

int countConsistentStrings(string allowed, vector<string>& words) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int freq[26]={0};
    for(char i: allowed){
        freq[i-'a']++;
    }

    int ans=0;
    for(string word: words){
        bool flag=true;
        for(char i: word){
            if(!freq[i-'a']){
                flag=false;
                break;
            }
        }
        ans += flag;
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