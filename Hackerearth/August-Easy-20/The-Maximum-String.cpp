// https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/maximum-substring-9b97fc5f/description/?layout=old
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


int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    string s;
    cin>>s;

    int n=s.length();

    int freq[26]={0};
    for(char i: s){
        freq[i-'a']++;
    }
    
    int mx=0;
    for(int i=0; i<26; i++){
        mx = max(mx, freq[i]);
    }

    vector<char>v;
    for(int i=0; i<26; i++){
        if(freq[i]==mx){
            v.push_back((char)(i+'a'));
        }
    }

    // for(char i: v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int idx;
    for(int i=0; i<n; i++){
        if(freq[s[i]-'a']==mx){
            idx=i;
            break;
        }
    }

    string ans="";
    ans += s[idx];
    int p=0;

    while(true){
        vector<int>av;
        for(int i=0; i<n; i++){
            if(s[i]==ans[p]){
                av.push_back(i);
            }
        }

        bool flag=false;
        for(int i=0; i<v.size(); i++){
            int ct=0;
            for(int j=0; j<av.size(); j++){
                if(s[av[j]+1] == v[i]){
                    ct++;
                }
            }
            if(ct == mx){
                ans += v[i];
                p++;
                break;
            }
            if(i==v.size()-1){
                flag=true;
                break;
            }
        }
        if(flag)break;
    }

    cout<<ans<<endl;
    return 0;
}