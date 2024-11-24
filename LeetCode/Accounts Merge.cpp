// https://leetcode.com/problems/accounts-merge/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
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

vector<int>parent;

int get(int a){
    if(parent[a] == a)return a;
    return parent[a] = get(parent[a]);
}

void union_sets(int a, int b){
    a = get(a);
    b = get(b);

    if(a != b){
        parent[b]=a;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string> >&accounts){
    int n = accounts.size();
    if(n == 1){
        sort(accounts[0].begin()+1, accounts[0].end());
        return accounts;
    }

    unordered_map<string, int>emailMap; // same email are present on which index
    parent = vector<int>(n, -1);
    vector<string> nameMap(n, ""); // maintain account holder name

    int i=0;
    for(auto &x: accounts){
        nameMap[i] = x[0];
        parent[i] = i;

        for(int y=1; y<x.size(); y++){
            if(emailMap.count(x[y])){ // if curr eamil is already present then union curr i and the earlier idx of email
                union_sets(i, emailMap[x[y]]);
            }
            else emailMap[x[y]]=i;
        }
        i++;
    }

    unordered_map<int, vector<string> >resmap;
    for(auto &it: emailMap){
        int p = get(it.second); // now for each email get his parent idx and push all email at that idx of same parent.
        resmap[p].push_back(it.first);
    }

    vector<vector<string> >ans;

    for(auto &it: resmap){
        sort(it.second.begin(), it.second.end());
        it.second.insert(it.second.begin(), nameMap[it.first]);
        ans.push_back(it.second);
    }

    return ans;
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