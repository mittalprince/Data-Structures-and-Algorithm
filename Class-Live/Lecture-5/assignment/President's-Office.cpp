#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    int n,m;
    cin>>n>>m;
    char president_color;
    cin>>president_color;
    char arr[n][m];
    vector<pair<int, int> >p_pos;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(president_color == arr[i][j]){
                p_pos.push_back({i,j});
            }
        }
    }

    map<char, bool>M;
    int ans=0;
    for(int i=0; i<p_pos.size(); i++){
        int l,k;
        l = p_pos[i].first;
        k = p_pos[i].second;

        if(l-1>=0 && arr[l-1][k] != '.' && arr[l-1][k] != president_color && !M[arr[l-1][k]]){
            M[arr[l-1][k]]=true;
            ans++;
        }
        if(l+1<n && arr[l+1][k] != '.' && arr[l+1][k] != president_color && !M[arr[l+1][k]]){
            M[arr[l+1][k]] = true;
            ans++;
        }
        if(k-1>=0 && arr[l][k-1] != '.' && arr[l][k-1] != president_color && !M[arr[l][k-1]]){
            M[arr[l][k-1]] = true;
            ans++;
        }
        if(k+1<m && arr[l][k+1] != '.' && arr[l][k+1] != president_color && !M[arr[l][k+1]]){
            M[arr[l][k+1]] = true;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}