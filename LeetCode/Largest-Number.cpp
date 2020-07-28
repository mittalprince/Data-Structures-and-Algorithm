// https://leetcode.com/problems/largest-number/
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

string largestNumber(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(nums.empty())return "";

    vector<string>arr;
    for(int i: nums){
        string s=to_string(i);
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), [&](const string a, const string b)->bool{
        string ab = a+b;
        string ba = b+a;

        return ab>ba;
    });

    string ans="";
    for(string i: arr){
        if(ans.empty() and i=="0")continue;
        ans += i;
    }
    if(ans.empty()) ans += "0";

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