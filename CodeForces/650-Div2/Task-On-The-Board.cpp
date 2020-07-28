#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

void solve(){
    string s;
    cin>>s;

    int m;
    cin>>m;
    int arr[m];
    ip(arr, m);

    int freq[26]={0};
    for(char i: s){
        freq[i-'a']++;
    }

    priority_queue<pair<char, int> >pq;
    for(int i=0; i<26; i++){
        if(freq[i]){
            pq.push({i+'a', freq[i]});
        }
    }

    int new_string_len=0;
    string ans(m, '.');

    while(new_string_len<m){
        vector<int>pos;
        for(int i=0; i<m; i++){
            if(arr[i]==0 and ans[i] == '.'){
                pos.push_back(i);
            }
        }
        while(pq.top().second < pos.size()){
            pq.pop();
        }
        for(int i: pos){
            for(int j=0; j<m; j++){
                if(arr[j]>0){
                    arr[j] -= abs(i-j);
                }
            }
            ans[i] = pq.top().first;
            new_string_len++;
        }
        pq.pop();
        if(new_string_len == m)break;
    }
    
    cout<<ans<<endl;
}

int main(){

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}