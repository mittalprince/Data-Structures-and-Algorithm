#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rows 13
#define cols 5

void matrix(int arr[][cols], int temp[][cols], int h){
    for(int i=0; i<h; i++){
        for(int j=0; j<cols; j++){
            arr[i][j]=temp[i][j];
        }
    }
}
void somePower(int h, int arr[][cols]){
    for(int i=h-5; i<h; i++){
        for(int j=0; j<cols; j++){
            if(arr[i][j] == -1){
                arr[i][j]=0;
            }
        }
    }
}

// wrong implementation, do not why
int findMaxcoreT(int arr[][cols], int h, int i, int j){
    if(i<0||j<0||i>=h||j>=cols){
        return 0;
    }

    int opt1 = arr[i][j]+findMaxcoreT(arr, h, i-1, j);
    int opt2 = arr[i][j]+findMaxcoreT(arr, h, i-1, j-1);
    int opt3 = arr[i][j]+findMaxcoreT(arr, h, i-1, j+1);

    return max(opt1, max(opt2, opt3));
}

void findMaxcore(int arr[][cols], int h, int i, int j, int &ans, int sum){
    if(i<0||j<0||j>=cols){
        return;
    }
    if(j==0 || i==0){
        sum += arr[i][j];
        ans = max(ans, sum);
        return;
    }
    sum += arr[i][j];
    findMaxcore(arr, h, i-1, j, ans, sum);
    findMaxcore(arr, h, i-1, j-1, ans, sum);
    findMaxcore(arr, h, i-1, j+1, ans, sum);

}

void solve(){
    int h;
    cin>>h;
    int arr[rows][cols], temp[rows][cols];
    memset(arr, 0, sizeof(arr));
    for(int i=0; i<h; i++){
        for(int j=0; j<cols; j++){
            cin>>arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    int ans=INT_MIN;
    if(h<=5){
        somePower(h, arr);
        findMaxcore(arr, h, h, 2, ans, 0);
    }
    else{
        for(int i=h; i>=5; i--){
            matrix(arr, temp, h);
            somePower(i, arr);
            findMaxcore(arr, h, h, 2, ans, 0);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
     while(t--){
         solve();
    }
    return 0;
}