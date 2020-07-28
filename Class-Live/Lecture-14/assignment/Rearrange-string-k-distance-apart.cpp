#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class comp{
    public:

    bool operator()(const pair<int, char>a, const pair<int, char>b){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

string rearrangeString(string s, int k){
    if(k==0) return s;
    int n=s.length();

    int arr[26]={0};
    for(char i: s){
        arr[i-'a']++;
    }

    priority_queue<pair<int, char>, vector<pair<int, char> >, comp>pq;

    for(int i=0; i<26; i++){
        if(arr[i]){
            pq.push({arr[i], i+'a'});
        }
    }

    string ans(n, '\0');
    int i=0;
    while(!pq.empty()){
        pair<int, char> top = pq.top();
        pq.pop();
        cout<<top.second<<" "<<top.first<<endl;
        int p = i;
        while(ans[p] != '\0')p++;

        for(int j=0; j<top.first; j++){
            if(p+(k*j) >= n){
                return "";
            }
            ans[p+(k*j)] = top.second;
        }
        i++;
    }

    return ans;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<rearrangeString(s, k)<<endl;
    return 0;
}