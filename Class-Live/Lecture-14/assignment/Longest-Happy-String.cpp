#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pi pair<int, char>

string longestDiverseString(int a, int b, int c) {
    priority_queue<pi>pq;

    pq.push({a, 'a'});
    pq.push({b, 'b'});
    pq.push({c, 'c'});

    string ans="";
    pi temp = {0, ' '};

    while(!pq.empty()){
        pi top = pq.top();
        pq.pop();

        if(temp.first){
            pq.push(temp);
            temp = {0, ' '};
        }

        if(*(ans.end()-1) == *(ans.end()-2) && *(ans.end()-1) == top.second){
            temp = top;
        }
        else{
            if(top.first == 0) break;
            ans += top.second;
            if(top.first > 0){
                top.first--;
                pq.push(top);
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}