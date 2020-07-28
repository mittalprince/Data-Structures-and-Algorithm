#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define MOD 1000000007

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s, t;
    cin>>s>>t;

    if(s.length() != t.length()){
        cout<<"-1\n";
        return 0;
    }
    
    vector<vector<ll> >dist(26, vector<ll>(26, INT_MAX));

    for(int i=0; i<26; i++)dist[i][i]=0;
    
    int edges;
    cin>>edges;

    for(int i=0; i<edges; i++){
        char u,v;
        ll w;
        cin>>u>>v>>w;
        dist[u-'a'][v-'a'] = min(dist[u-'a'][v-'a'], w);
    }
    
    for(int k=0; k<26; k++){
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    
    // for(int i=0; i<26; i++){
    //     for(int j=0; j<26; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll min_cost=0;
    string ans="";

    for(int i=0; i<s.length(); i++){
        if(s[i] != t[i]){
            char curr_min_char;
            ll curr_min_cost=INT_MAX;
            for(int j=0; j<26; j++){
                if(dist[s[i]-'a'][j]+dist[t[i]-'a'][j] < curr_min_cost){
                    curr_min_cost = dist[s[i]-'a'][j]+dist[t[i]-'a'][j];
                    curr_min_char = 'a'+j;
                }
            }
            if(curr_min_cost == INT_MAX){
                cout<<"-1\n";
                return 0;
            }
            min_cost += curr_min_cost;
            ans.push_back(curr_min_char);
        }
        else{
            ans.push_back(s[i]);
        }
    }
    

    cout<<min_cost<<endl;
    cout<<ans<<endl;
    return 0;
}