#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int largestRectangleArea(vector<char>& arr) {
    stack<int>s;
    int area=0, i=0;

    for(i=0; i<arr.size(); i++){
        if(!s.empty() && arr[i] <= arr[s.top()]){
            while(!s.empty() && arr[i] <= arr[s.top()]){
                int ht=arr[s.top()]-'0';
                s.pop();   
                area = max(area, (ht*(s.empty()?i:i-s.top()-1)));
            }
        }
        s.push(i);
    }

    while(!s.empty()){
        int ht=arr[s.top()]-'0';
        s.pop();   
        area = max(area, (ht*(s.empty()?i:i-s.top()-1)));
    }
    return area;
}

int maximalRectangle(vector<vector<char> >&arr){
    int area=0;
    int n=arr.size();
    if(n==0) return 0;
    
    int m=arr[0].size();
    
    int ct=0;
    for(int j=0; j<m; j++){
        if(arr[0][j]=='1') ct++;
        else{
            area = max(area, ct);
            ct=0;
        }
    }
    area = max(area, ct);
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '1'){
                arr[i][j] = ((arr[i][j]-'0') +(arr[i-1][j]-'0'))+'0';
            }
        }
        area = max(area, largestRectangleArea(arr[i]));
    }
    return area;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}