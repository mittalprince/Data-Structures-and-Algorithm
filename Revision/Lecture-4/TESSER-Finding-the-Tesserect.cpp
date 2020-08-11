// https://www.spoj.com/problems/TESSER/
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
#define MAX 1000005
int table[MAX] = {0};

string pattern, text;

void buildResettable(){
    int len = pattern.length();
    int i=1, j=0;
    while(i<len){
        while(j>0 and pattern[i] != pattern[j]){
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]){
            table[i] = j+1;
            i++;
            j++;
        }
        else if(j==0)table[i++]=0;
    }
}

void solve(){
    int n;
    cin>>n;
    int arr[n];
    ip(arr, n);

    text="";
    for(int i=1; i<n; i++){
        if(arr[i]>arr[i-1])text+='G';
        else if(arr[i]<arr[i-1])text += 'L';
        else text += 'E';
    }
    cin.ignore(256, '\n');
    cin>>pattern;

    buildResettable();
    int lp=pattern.length();
    int lt=text.length();

    int i=0, j=0;
    while(i<n){
        while(j>0 and pattern[j] != text[i]){
            j = table[j-1];
        }
        if(pattern[j]==text[i]){
            i++;j++;
        }
        else i++;
        if(j==lp){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}