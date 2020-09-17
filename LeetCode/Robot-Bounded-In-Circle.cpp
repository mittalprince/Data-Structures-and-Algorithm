// https://leetcode.com/problems/robot-bounded-in-circle/
#include<iostream>
#include<vector>
#include<unordered_map>
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

bool isRobotBounded(string instructions) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<char, pair<char, char> >dir;
    dir['N'] = {'W','E'};
    dir['S'] = {'E','W'};
    dir['E'] = {'N','S'};
    dir['W'] = {'S','N'};

    unordered_map<char, pair<int, int> >moves;
    moves['N']={0,1};
    moves['S']={0,-1};
    moves['E']={1,0};
    moves['W']={-1,0};

    int i=0, j=0;
    char face='N';

    for(char s:instructions){
        if(s=='L'){
            face = dir[face].first;
        }
        else if(s=='R'){
            face = dir[face].second;
        }
        else{
            i += moves[face].first;
            j += moves[face].second;
        }
    }

    return ((i==0 and j==0) or face!='N');
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