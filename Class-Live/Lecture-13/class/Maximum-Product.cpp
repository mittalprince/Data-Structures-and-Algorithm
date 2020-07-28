#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

string a,b;
pair<ll, string> dp[20][2][2][2];

pair<ll, string> solve(int pos, bool tight_a, bool tight_b, bool start){
    if(pos == a.size()){
        return {1, ""};
    }

    if(dp[pos][tight_a][tight_b][start].first != -1){
        return dp[pos][tight_a][tight_b][start];
    }

    int lb = ((tight_a)?(a[pos]-'0'):0);
    int up = ((tight_b)?(b[pos]-'0'):9);

    pair<ll, string> ans(-1, "");

    for(int i=lb; i<=up; i++){
        int val;
        if(start == 0 && i==0){
            val = 1;
        }
        else val = i;
        pair<ll, string> x = solve(pos+1, tight_a&&(i==lb), tight_b&&(i==up), (start||i>0));
        if(val*x.first > ans.first){
            ans.first = val*x.first;

            if(start == 0 && i==0){
                ans.second = x.second;
            }
            else {
                reverse(x.second.begin(), x.second.end());
                x.second.push_back(i+'0');
                reverse(x.second.begin(), x.second.end());
                ans.second = x.second;
            }
        }
    }
    return dp[pos][tight_a][tight_b][start] = ans;
}

int main(){
    cin>>a>>b;
    reverse(a.begin(), a.end());

    while(a.size()<b.size()){
        a.push_back('0');
    }

    reverse(a.begin(), a.end());

    for(int i=0; i<20; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                for(int l=0; l<2; l++){
                    dp[i][j][k][l].first = -1;
                }
            }
        }
    }
    pair<ll, string> ans = solve(0, 1, 1, 0);

    cout<<ans.second<<endl;
    return 0;
}