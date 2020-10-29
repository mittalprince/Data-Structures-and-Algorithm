// https://leetcode.com/problems/repeated-dna-sequences/
#include<iostream>
#include<vector>
#include<map>
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

vector<string> findRepeatedDnaSequences(string s) {
    map<string, int>m;

    for(int i=0; i<s.length(); i++){
        if(i>=9){
            string t = s.substr(i-9, 10);
            // cout<<t<<endl;
            m[t]++;
        }
    }

    vector<string>ans;
    for(auto it: m){
        if(it.second>1){
            ans.push_back(it.first);
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