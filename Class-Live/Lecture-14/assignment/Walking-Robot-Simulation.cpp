#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int x=0, y=0, di=0;

    // di->0(north), di->1(east), di->2(south), d1->3(west)

    map<pair<int, int>, bool> obs;
    for(auto it: obstacles){
        obs[{it[0], it[1]}]=true;
    }

    int ans=0;
    for(int i: commands){
        if(i==-1){
            di = (di+1)%4; // make 90 deg right shift
        }
        else if(i==-2){
            di = (di+3)%4; // make 90 deg left shif
        }
        else{
            for(int k=0; k<i; k++){
                int nx = x+dx[di];
                int ny = y+dy[di];

                if(obs.find({nx, ny}) == obs.end()){
                    x=nx;
                    y=ny;
                    ans = max(ans, x*x + y*y);
                }
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