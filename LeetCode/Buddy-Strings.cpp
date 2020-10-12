//https://leetcode.com/problems/buddy-strings/ 
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

bool buddyStrings(string A, string B) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(A.length()!=B.length())return false;
    int n=A.length();
    vector<int>pos;

    int freq[26]={0};

    for(int i=0; i<n; i++){
        if(A[i]!=B[i]){
            pos.push_back(i);
        }
        freq[A[i]-'a']++;
    }
    int sz = pos.size();
    if(sz==0){
        for(int i=0; i<26; i++){
            if(freq[i]>=2)return true;
        }
        return false;
    }
    if(sz==1 or sz>2)return false;

    return (A[pos[0]] == B[pos[1]] and A[pos[1]] == B[pos[0]]);
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