// https://leetcode.com/problems/maximal-rectangle/
#include<iostream>
#include<vector>
#include<stack>
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

int findLargestArea(vector<char>&arr){
    stack<int>s;
    int area=0, i=0;
    int n=arr.size();

    for(i=0; i<n;){
        if(!s.empty() and arr[i] <= arr[s.top()]){
            int ht = arr[s.top()]-'0';
            s.pop();
            if(s.empty()){
                area = max(area, ht*i);
            }
            else{
                area = max(area, ht*(i-s.top()-1));
            }
        }
        else s.push(i++);
    }

    while(!s.empty()){
        int ht = arr[s.top()]-'0';
        s.pop();
        if(s.empty()){
            area = max(area, ht*i);
        }
        else{
            area = max(area, ht*(i-s.top()-1));
        }
    }
    return area;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int max_area=0;
    int n=matrix.size();

    int m=n?matrix[0].size():0;

    if(!n or !m)return 0;

    int ct=0;
    for(int i=0; i<m; i++){
        if(matrix[0][i]=='1')ct++;
        else{
            max_area = max(max_area, ct);
            ct=0;
        }
    }
    max_area = max(max_area, ct);

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]=='1'){
                matrix[i][j] = ((matrix[i][j]-'0')+(matrix[i-1][j]-'0'))+'0';
            }
        }
        max_area = max(max_area, findLargestArea(matrix[i]));
    }

    return max_area;
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