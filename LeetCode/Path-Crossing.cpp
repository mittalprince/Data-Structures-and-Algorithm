#include<iostream>
#include<vector>
using namespace std;
#include<set>
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define ip1(arr, n) for(int i=1; i<=n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define debug(x) cout<<x<<"\n";
#define inf 1e9
#define INF 1e16
#define MOD 1000000007

/*
Given a string path, where path[i] = 'N', 'S', 'E' or 'W', each representing moving one unit north, south, east, or west, respectively. You start at the origin (0, 0) 
on a 2D plane and walk on the path specified by path.
Return True if the path crosses itself at any point, that is, if at any time you are on a location you've previously visited. Return False otherwise.
*/

bool isPathCrossing(string path) {
    set<pair<int, int> >s;
    s.insert({0,0});
    int x=0, y=0;
    for(char i: path){
        if(i=='E'){
            x++;
        }
        else if(i == 'W')x--;
        else if(i=='N')y++;
        else y--;

        if(s.count({x,y}))return true;
        s.insert({x,y});
    }
    return false;
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