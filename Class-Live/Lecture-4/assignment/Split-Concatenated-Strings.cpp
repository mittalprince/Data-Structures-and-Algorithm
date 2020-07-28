#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

void dfs(vector<string>arr, int n, int i, string curr_str, string& res){
    if(i<n){

        dfs(arr, n, i+1, curr_str+arr[i], res);
        reverse(arr[i].begin(), arr[i].end());
        dfs(arr, n, i + 1, curr_str + arr[i], res);
    }
    else{
        for(int j=0; j<curr_str.length(); j++){
            string temp = curr_str.substr(j) + curr_str.substr(0, j);
            if(temp.compare(res) > 0) res=temp;
        }
    }
}

string splitLoopedStringusingDFS(vector<string>& arr){
    int n=arr.size();
    string res="",curr_str="";
    dfs(arr, n ,0, curr_str, res);
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<splitLoopedStringusingDFS(arr)<<endl;
    return 0;
}