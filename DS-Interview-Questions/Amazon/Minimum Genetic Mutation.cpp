// https://leetcode.com/problems/minimum-genetic-mutation/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
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

int minMutation(string start, string end, vector<string>& bank) {
    //st holds all valid mutations
    unordered_set<string> st{bank.begin(),bank.end()};
    //if end mutaion is not in list return -1;
    if(!st.count(end)) return -1;
    //start BFS by pushing the starting mutation
    queue<string> Q;
    Q.push(start);
    int steps=0,s;
    string cur,t;
    while(!Q.empty()){
        s=Q.size();
        while(s--){
            cur=Q.front();
            Q.pop();
            //If we reach end mutation
            if(cur==end) return steps;
            //We erase the cur mutation in order to avoid redundant checking
            st.erase(cur);
            //as the length of mutation is 8 and it can take A,C,G,T
            //at each index we check the possibility of mutation by replcaing it with A,C,G,T
            for(int i=0;i<8;i++){
                t=cur;
                t[i]='A';
                if(st.count(t)) Q.push(t);
                t[i]='C';
                if(st.count(t)) Q.push(t);
                t[i]='G';
                if(st.count(t)) Q.push(t);
                t[i]='T';
                if(st.count(t)) Q.push(t);
            }
        }
        steps++;
    }
    return -1;
}

int main(){

/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
*/

    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}