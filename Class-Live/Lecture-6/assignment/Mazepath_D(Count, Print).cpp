#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

bool checkValidPath(int n, int m, int i, int j){
    if(i<0||j<0||i>=n||j>=m) return false;
    return true;
}

void findPath(int n, int m, int i, int j, string output, int &ct){
    if(!checkValidPath(n, m, i, j)) return;
    if(i==(n-1) && j==(m-1)){
        ct++;
        cout<<output<<" ";
        return;
    }

    output += 'V';
    findPath(n, m, i + 1, j, output, ct);
    output.pop_back();
    output += 'H';
    findPath(n, m, i, j+1, output, ct);
    output.pop_back();
    output += 'D';
    findPath(n, m, i+1, j+1, output, ct);
}
int main(){
    int n,m;
    cin>>n>>m;
    string output;
    int ct=0;
    findPath(n, m, 0, 0, output, ct);
    cout<<endl<<ct<<endl;
    return 0;
}