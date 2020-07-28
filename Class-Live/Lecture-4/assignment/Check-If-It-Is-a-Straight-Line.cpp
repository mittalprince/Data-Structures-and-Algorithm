#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int slope(vector<int>&x,vector<int>&y){
    int f=y[1]-x[1];
    if(f==0) return 111;
    return ((y[0]-x[0])/f);
}
bool checkStraightLine(vector<vector<int> >&coordinates){
    int res=slope(coordinates[0],coordinates[1]);
    for(int j=1;j<coordinates.size()-1;j++)
    {
        int ch=slope(coordinates[j],coordinates[j+1]);
        if(ch!=res)
            return false;
    }
    return true;
}

int main(){
    int n;
    vector<vector<int> >coordinates(n, vector<int>(2));
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        coordinates[i] = {x,y};
    }
    if(checkStraightLine(coordinates))cout<<"true\n";
    else cout<<"false\n";
    return 0;
}