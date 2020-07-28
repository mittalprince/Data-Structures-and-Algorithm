#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int largestRectangleArea(vector<int>& arr) {
    stack<int>s;
    int area=0, i=0;

    for(i=0; i<arr.size(); i++){
        if(!s.empty() && arr[i] <= arr[s.top()]){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                int ht=arr[s.top()];
                s.pop();   
                area = max(area, (ht*(s.empty()?i:i-s.top()-1)));
            }
        }
        s.push(i);
    }

    while(!s.empty()){
        int ht=arr[s.top()];
        s.pop();   
        area = max(area, (ht*(s.empty()?i:i-s.top()-1)));
    }
    return area;
}

int maxRectangle(vector<vector<int> >&arr){
    int area=0;
    int n=arr.size(), m=arr[0].size();

    int ct=0;
    for(int j=0; j<m; j++){
        if(arr[0][j]==1) ct++;
        else{
            area = max(area, ct);
            ct=0;
        }
    }
    area = max(area, ct);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]){
                arr[i][j] += arr[i-1][j];
            }
        }
        area = max(area, largestRectangleArea(arr[i]));
    }
    return area;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> >arr(n, vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    cout<<maxRectangle(arr)<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}