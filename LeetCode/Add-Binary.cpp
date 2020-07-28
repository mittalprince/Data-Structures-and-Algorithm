// https://leetcode.com/problems/add-binary/
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

class Node{
public:
    int data;
    Node *left, *right;
    Node():data(0),left(NULL),right(NULL){}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

string addBinary(string a, string b) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=a.length();
    int m=b.length();

    if(!n)return b;
    if(!m)return a;

    string ans="";
    int carry=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i=0, j=0;

    while(i<n and j<m){
        int t1=a[i]-'0';
        int t2=b[j]-'0';
        int val = t1+t2+carry;
        carry = val/2;
        val = val%2;
        ans += (val+'0');
        i++;
        j++;
    }

    while(i<n){
        int t1=a[i]-'0';
        int val = t1+carry;
        carry = val/2;
        val = val%2;
        ans += (val+'0');
        i++;
    }
    while(j<m){
        int t1=b[j]-'0';
        int val = t1+carry;
        carry = val/2;
        val = val%2;
        ans += (val+'0');
        j++;
    }
    if(carry){
        ans += "1";
    }
    reverse(ans.begin(), ans.end());
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