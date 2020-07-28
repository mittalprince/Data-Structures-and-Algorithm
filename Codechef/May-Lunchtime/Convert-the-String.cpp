#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

void solve(){
    int n;
    cin>>n;
    map<char, int>ma;
    map<char, vector<int> >mb;
    int arr[26]={0};

    string a,b;
    cin>>a>>b;
    for(int i=0; i<n; i++){
        if(a[i]<b[i]){
            cout<<"-1\n";
            return;
        }
        arr[a[i]-'a']++;
        ma[a[i]]=i;
    }

    for(int i=0; i<n; i++){
        if(a[i] != b[i]){
            mb[b[i]].push_back(i);
        }
    }

    ll operations=0;
    for(int i=25; i>=0; i--){
        char ch = i+'a';
        if(mb.find(ch) != mb.end()){
            if(ma.find(ch) == ma.end()){
                cout<<"-1\n";
                return;
            }
            mb[ch].push_back(ma[ch]);
            operations++;
        }
    }

    cout<<operations<<endl;
    for(int i=25; i>=0; i--){
        char ch = i+'a';
        if(mb.find(ch) != mb.end()){
            cout<<mb[ch].size()<<" ";
            for(int j: mb[ch]){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
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