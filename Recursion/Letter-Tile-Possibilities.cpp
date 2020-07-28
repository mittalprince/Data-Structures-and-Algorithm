// https://leetcode.com/problems/letter-tile-possibilities/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
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

int fact[10];
unordered_set<string>s;

void factorial(){
    fact[0]=fact[1]=1;
    for(int i=2; i<=8; i++){
        fact[i] = i*fact[i-1];
    }
}

int uniqueComb(string str){
    int freq[26]={0};
    for(char i: str)freq[i-'A']++;

    int ans = fact[str.length()];
    for(int i=0; i<26; i++){
        ans /= fact[freq[i]];
    }
    return ans;
}

void solve(string tiles, int i, string curr, int &ans){
    if(i>=tiles.length()){
        if(s.find(curr) == s.end()){
            s.insert(curr);
            ans += uniqueComb(curr);
        }
        return;
    }

    solve(tiles, i+1, curr+tiles[i], ans);
    solve(tiles, i+1, curr, ans);
}

int numTilePossibilities(string tiles) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();
    int ans=0;
    sort(tiles.begin(), tiles.end());
    solve(tiles, 0, "", ans);
    return ans-1;
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