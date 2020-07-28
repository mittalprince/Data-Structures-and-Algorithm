// https://leetcode.com/problems/satisfiability-of-equality-equations/
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

#define MAX 26

vector<int>parent;

int find(int a){
    if(parent[a] == a)return a;
    return parent[a] = find(parent[a]);
}

void union_sets(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parent[b]=a;
    }
}

bool equationsPossible(vector<string>& equations) {
    int n = equations.size();

    parent = vector<int>(MAX, -1);
    for(int i=0; i<26; i++)parent[i]=i;


    for(int i=0; i<n; i++){
        int a = equations[i][0]-'a';
        int b = equations[i][3]-'a';

        if(equations[i][1] == '='){
           union_sets(a, b);
        }
    }

    for(string i: equations){
        int a = i[0]-'a';
        int b = i[3]-'a';

        if(i[1] == '!'){
           if(find(a) == find(b))return false;
        }

    }
    return true;
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