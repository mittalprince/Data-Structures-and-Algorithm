#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

bool check(string &a, string &b){
    bool isChanged=false;
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            if(isChanged)return false;
            isChanged=true;
        }
    }
    return true;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    wordList.push_back(beginWord);
    int n = wordList.size();

    vector<bool> vis(n,0);
    vector<vector<int>> adj(n);
    vector<vector<string>> res;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
           if (check(wordList[i], wordList[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    queue<vector<int> >q;
    q.push({n-1});
    vis[n-1]=1;
    bool found=false;

    while(!q.empty() and !found){
        int size = q.size();
        for(int i=0; i<size; i++){
            vector<int>top = q.front();
            q.pop();

            vis[top.back()]=1;

            for(auto child: adj[top.back()]){
                if(vis[child])continue;
                top.push_back(child);
                q.push(top);

                if(wordList[top.back()] == endWord){
                    vector<string>str;
                    for(int i: top){
                        str.push_back(wordList[i]);
                    }
                    res.push_back(str);
                    found=true;
                }
                top.pop_back();
            }
        }
    }
    return res;
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