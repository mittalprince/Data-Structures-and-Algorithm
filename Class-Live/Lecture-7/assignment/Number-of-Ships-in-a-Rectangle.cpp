#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

class Sea{
    public:    
    bool hasShips(vector<int>&topRight, vector<int>&bottomLeft);
};

int solve(Sea &sea, vector<int>topRight, vector<int>bottomLeft){
    // topRight[0] -> right
    // topRight[1] -> top
    // bottomLeft[0] -> left
    // bottomLeft[1] -> bottom

    if(topRight[0]<bottomLeft[0] || topRight[1]<bottomLeft[1] || !sea.hasShips(topRight, bottomLeft)){
        return 0;
    }

    if(topRight[0] == bottomLeft[0] && topRight[1] == bottomLeft[1]){
        return 1;
    }

    int midx = bottomLeft[0]+(topRight[0]-bottomLeft[0])/2;
    int midy = bottomLeft[1]+(topRight[1]-bottomLeft[1])/2;

    int ct=0;

    ct += solve(sea, {midx, midy}, bottomLeft);
    ct += solve(sea, topRight ,{midx+1, midy+1});
    ct += solve(sea, {topRight[0], midy}, {midx+1, bottomLeft[1]});
    ct += solve(sea, {midx, topRight[1]}, {bottomLeft[0], midy+1});

    return ct;
}

int countShips(Sea &sea, vector<int> topRight, vector<int> bottomLeft){
    int ans = solve(sea, topRight, bottomLeft);
    return ans;    
}

int main(){
    vector<int> topRight(2), bottomLeft(2);
    for(int i=0; i<2; i++){
        cin>>topRight[i];
    }    
    for(int i=0; i<2; i++){
        cin>>bottomLeft[i];
    }    

    return 0;
}