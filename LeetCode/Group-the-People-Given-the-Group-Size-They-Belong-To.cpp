#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    map<int, vector<int>>m;

    for(int i=0; i<groupSizes.size(); i++){
        m[groupSizes[i]].push_back(i);
    }

    vector<vector<int> >ans;

    for(auto it: m){
        int size=it.first;
        vector<int>t;

        while(!it.second.empty()){
            for(int i=0; i<size; i++){
                t.push_back(it.second.back());
                it.second.pop_back();
            }  
            if(!t.empty())ans.push_back(t);
            t.clear();

        }

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