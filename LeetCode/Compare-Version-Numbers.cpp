// https://leetcode.com/problems/compare-version-numbers/
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

int compareVersion(string V1, string V2) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i=0, j=0, n1=V1.length(), n2=V2.length();

    while(i<n1 or j<n2){
        int v1=0, v2=0;
        while(i<n1 and V1[i]!='.')v1 = v1*10+(V1[i++]-'0');
        while(j<n2 and V2[j]!='.')v2 = v2*10+(V2[j++]-'0');
        if(v1>v2)return 1;
        else if(v1<v2)return -1;

        i++, j++;
    }

    return 0;
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