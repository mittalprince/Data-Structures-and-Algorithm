// https://leetcode.com/problems/largest-time-for-given-digits/
#include<iostream>
#include<vector>
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

bool check(vector<int>A, int h, int m){
    sort(A.begin(), A.end());
    vector<int>arr(4);
    arr[0] = h/10;
    arr[1] = h%10;
    arr[2] = m/10;
    arr[3] = m%10;

    sort(arr.begin(), arr.end());
    return (arr == A);
}

string largestTimeFromDigits(vector<int>& A) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ans="";
    for(int h=23; h>=0 and ans==""; h--){
        for(int m=59; m>=0 and ans==""; m--){
            if(check(A, h, m)){
                ans.push_back('0' + h/10);
                ans.push_back('0' + h%10);
                ans.push_back(':');
                ans.push_back('0' + m/10);
                ans.push_back('0' + m%10);
                break;
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