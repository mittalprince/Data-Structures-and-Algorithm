// https://leetcode.com/problems/sequential-digits/
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
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

vector<int> sequentialDigits(int low, int high) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "123456789";
    vector<int>ans;

    for(int i=0; i<s.length(); i++){
        for(int j=i; j<s.length(); j++){
            string t = s.substr(i, j-i+1);
            int val = stoi(t);
            if(val>=low and val<=high){
                ans.push_back(val);
            }
        }
    }
    sort(ans.begin(), ans.end());
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