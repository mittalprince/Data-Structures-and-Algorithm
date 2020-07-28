#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
#define ip(arr, n) for(int i=0; i<n; i++) cin>>arr[i];
#define op(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";
#define fstIO ios_base::sync_with_stdio(false); cin.tie(NULL);

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    map<int, int>wmc;

    for(string i: words){
        int mask=0;
        for(char j:i){
            mask |= (1<<(j-'a'));
        }
        wmc[mask]++;
    }

    vector<int>ans(puzzles.size(), 0);

    for(int i=0; i<puzzles.size(); i++){
        string p = puzzles[i];

        for(int j=0; j<(1<<6); j++){
            int mask = (1<<(p[0]-'a'));

            for(int k=0; k<6; k++){
                if(j&(1<<k)){
                    mask |= (1<<(p[k+1]-'a'));
                }
            }

            ans[i] += wmc[mask];
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    return 0;
}