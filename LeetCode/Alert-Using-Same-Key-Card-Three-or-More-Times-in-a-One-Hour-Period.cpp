// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
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

vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, vector<int> >m;
    int n = keyName.size();
    for(int i=0; i<n; i++){
        int x, y;
        sscanf(keyTime[i].c_str(), "%d:%d", &x, &y);
        m[keyName[i]].push_back(x*60+y);
    }

    set<string>res;
    for(auto it: m){
        vector<int>t = it.second;
        sort(begin(t), end(t));
        for(int i=0; i<t.size()-2; i++){
            if(t[i+2]-t[i]<=60){
                res.insert(it.first);
            }
        }
    }

    vector<string>ans;
    for(string i: res){
        ans.push_back(i);
    }

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