//https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
#include<iostream>
#include<vector>
#include<unordered_set>
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

unordered_set<string>t;
string ans;
int a,b,n;

bool isVisited(string s){
    return t.find(s)!=t.end();
}

void visit(string s){
    ans = min(ans, s);
    t.insert(s);
}

string rotate(string s, int x){
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin()+x);
    reverse(s.begin()+x, s.end());
    return s;    
}

string add(string s, int x) {
    for (int i=1; i<n; i += 2) {
        char &c = s[i];
        c = '0' + (c-'0'+x)%10;
    }
    return s;
}

void dfs(string s){
    if(isVisited(s)){
        return;
    }    
    visit(s);
    dfs(rotate(s, b));
    dfs(add(s, a));
}

string findLexSmallestString(string s, int A, int B) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ans = s;
    a = A;
    b = B;
    n = s.size();
    dfs(s);
    return ans;
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