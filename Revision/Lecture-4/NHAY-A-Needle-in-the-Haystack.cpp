// https://www.spoj.com/problems/NHAY/
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
#define MAX 10000000

ll table[MAX];
string pattern, text;

void buildResetTable(){
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
        else if(j==0){
            table[i]=0;
            i++;
        }
    }
}

void solve(){
    int lp = pattern.length();
    int lt = text.length();

    bool flag = (lp<=lt), check=false;

    if(flag){
        buildResetTable();
        int i=0, j=0;
        while(i<lt){
            while(j>0 and pattern[j] != text[i]){
                j = table[j-1];
            }
            if(text[i] == pattern[j]){
                i++;
                j++;
            }
            else i++;
            if(j==lp){
                cout<<(i-lp)<<endl;
                check=true;
            }
        }
    }
    if(!check)cout<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    while(cin>>n){
        cin.ignore(256, '\n');
        getline(cin, pattern);
        getline(cin, text);

        solve();
    }
    return 0;
}