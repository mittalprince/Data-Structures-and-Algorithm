#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

int solve(string start, string target, set<string>&D){
    if(D.find(target) == D.end())return 0;

    int level=0, wordLen=target.length();

    queue<string>q;
    q.push(start);

    while(!q.empty()){
        level++;

        int qSize=q.size();
        for(int i=0; i<qSize; i++){
            string curr = q.front();
            q.pop();

            for(int pos=0; pos<wordLen; pos++){
                char actual_val = curr[pos];
                for(char c='a'; c<='z'; c++){
                    curr[pos]=c;
                    if(curr == target)return level+1;
                    if(D.find(curr) == D.end())continue; // if curr word that we make is not exist in wordList just continue
                    q.push(curr); // otherwise push this work in queue so that we can change its char to make target
                    D.erase(curr); // and remove this from Set so that no other same word we make again
                }
                curr[pos]=actual_val;
            }
        }
    }
    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    
    set<string>s(wordList.begin(), wordList.end());
    return solve(beginWord, endWord, s);
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